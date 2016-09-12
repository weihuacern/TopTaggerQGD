#include <vector>
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <stdlib.h>

#include "TFile.h"
#include "TList.h"
#include "TLine.h"
#include "TString.h"
#include "TH1D.h"
#include "TCanvas.h"
#include "TPad.h"
#include "TLegend.h"
#include "TLatex.h"
#include "TStyle.h"
#include "TExec.h"

class TopTaggerQGDPlots
{
 public:
  std::string target_DIR;

  TFile * finCheck;
  TList * listCheck;

  TFile * finEff;
  TList * listEff;

  TFile * finMisTag;
  TList * listMisTag;

  std::string lumi_str;  

  double scale = 1;

  void Initialization(std::string dir); 
  void PrintPlotsName();
  void JetsComparePlots(
                       TString hist_tag,
                       TString XTitle,
                       double min,
                       double max
                       );
  void EffPlots(
                TString hist_tag,
                TString XTitle,
                double min,
                double max
               );
  void MisTagRatePlots(
                       TString hist_tag,
                       TString XTitle,
                       double min,
                       double max
                      );
};

void TopTaggerQGDPlots::Initialization(std::string dir)
{
  target_DIR = dir;
  system( ("mkdir " + dir).c_str() );

  finCheck = TFile::Open("RootForPlotting/TopTaggerQGDCheck.root");
  listCheck = finCheck->GetListOfKeys();
  finEff = TFile::Open("RootForPlotting/TopTaggerEff.root");
  listEff = finEff->GetListOfKeys();
  finMisTag = TFile::Open("RootForPlotting/TopTaggerMisTag.root");
  listMisTag = finMisTag->GetListOfKeys();
}

void TopTaggerQGDPlots::PrintPlotsName()
{
  for(int i  = 0 ; i < listEff->GetSize() ; i++)
  {
    std::cout<<"Name: "<< listEff->At(i)->GetName() << "("<< i <<")"<<std::endl;
  }
 
  for(int i  = 0 ; i < listMisTag->GetSize() ; i++)
  {
    std::cout<<"Name: "<< listMisTag->At(i)->GetName() << "("<< i <<")"<<std::endl;
  }
 
  return ;
}

void TopTaggerQGDPlots::JetsComparePlots(
                                         TString hist_tag,
                                         TString XTitle,
                                         double min,
                                         double max
                                        )
{ 
  TH1D * h_ljets;
  TH1D * h_cjets;
  TH1D * h_bjets;
  TH1D * h_gjets;
  TH1D * h_pjets;

  int NHist = listCheck->GetSize();;

  for(int i  = 0 ; i < NHist ; i++)
  {
    if( TString(listCheck->At(i)->GetName()).Contains( hist_tag ) )
    {
      if( TString(listCheck->At(i)->GetName()).Contains( "_ljets" ) )
      {
        h_ljets = (TH1D*)finCheck->Get(listCheck->At(i)->GetName())->Clone();
      }
      if( TString(listCheck->At(i)->GetName()).Contains( "_cjets" ) )
      { 
        h_cjets = (TH1D*)finCheck->Get(listCheck->At(i)->GetName())->Clone();
      }
      if( TString(listCheck->At(i)->GetName()).Contains( "_bjets" ) )
      { 
        h_bjets = (TH1D*)finCheck->Get(listCheck->At(i)->GetName())->Clone();
      }
      if( TString(listCheck->At(i)->GetName()).Contains( "_gjets" ) )
      {
        h_gjets = (TH1D*)finCheck->Get(listCheck->At(i)->GetName())->Clone();
      }
      if( TString(listCheck->At(i)->GetName()).Contains( "_pjets" ) )
      {
        h_pjets = (TH1D*)finCheck->Get(listCheck->At(i)->GetName())->Clone();
      }
    }
    else
      continue;
  }

  TCanvas *c = new TCanvas("c","A Simple Graph Example",200,10,700,500);
  //c->SetLogy();
  gStyle->SetOptStat(0);

  h_ljets->GetXaxis()->SetRangeUser(min,max);
  h_ljets->GetXaxis()->SetTitle(XTitle);
  //h_ljets->GetYaxis()->SetRangeUser(1000,10000000);
  h_ljets->SetLineColor(1);

  h_cjets->GetXaxis()->SetRangeUser(min,max);
  h_cjets->GetXaxis()->SetTitle(XTitle);
  h_cjets->SetLineColor(2);

  h_bjets->GetXaxis()->SetRangeUser(min,max);
  h_bjets->GetXaxis()->SetTitle(XTitle);
  h_bjets->SetLineColor(3);

  h_gjets->GetXaxis()->SetRangeUser(min,max);
  h_gjets->GetXaxis()->SetTitle(XTitle);
  h_gjets->SetLineColor(4);

  h_pjets->GetXaxis()->SetRangeUser(min,max);
  h_pjets->GetXaxis()->SetTitle(XTitle);
  h_pjets->SetLineColor(5);

  h_ljets->Draw();
  h_cjets->Draw("same");
  h_bjets->Draw("same");
  h_gjets->Draw("same");
  h_pjets->Draw("same");

  //Create LUMI stamp
  const std::string titre="CMS Preliminary 2016";
  TLatex *title = new TLatex(0.09770115,0.9194915,titre.c_str());
  title->SetNDC();
  title->SetTextSize(0.045);
  title->Draw("same");

  //Create Legend
  TLegend* leg = new TLegend(0.55,0.75,0.80,0.90);
  leg->SetBorderSize(1);
  leg->SetLineColor(1);
  leg->SetLineWidth(2);
  leg->SetFillColor(0);
  leg->SetTextFont(42);
  leg->SetTextSize(0.03);
  //leg->SetHeader("QCD HT MC : Jet Type");
  leg->SetHeader("TTJets Inc MC : Jet Type");
  leg->AddEntry(h_ljets,"Light Quark Jet");
  leg->AddEntry(h_cjets,"C Quark Jet");
  leg->AddEntry(h_bjets,"B Quark Jet");
  leg->AddEntry(h_gjets,"Gluon Jet");
  leg->AddEntry(h_pjets,"Pileup Jet");
  leg->Draw("same");

  c->SaveAs( target_DIR + TString("/") + hist_tag + TString(".png") );
  c->SaveAs( target_DIR + TString("/") + hist_tag + TString(".pdf") );
  c->SaveAs( target_DIR + TString("/") + hist_tag + TString(".C") );
  return ;
}

void TopTaggerQGDPlots::EffPlots(
                                 TString hist_tag,
                                 TString XTitle,
                                 double min,
                                 double max
                                )
{
  TH1D *eff_h_d;
  TH1D *eff_h_n_normal;
  TH1D *eff_h_n_mctruth;
  TH1D *eff_h_n_qgd;

  int NHist = listEff->GetSize();;

  for(int i  = 0 ; i < NHist ; i++)
  {
    if( TString(listEff->At(i)->GetName()).Contains( hist_tag ) )
    {
      if( TString(listEff->At(i)->GetName()).Contains( "_denominator_" ) )
      {
        eff_h_d = (TH1D*)finEff->Get(listEff->At(i)->GetName())->Clone();
      }
      if( TString(listEff->At(i)->GetName()).Contains( "_numerator_normal_" ) )
      {
        eff_h_n_normal = (TH1D*)finEff->Get(listEff->At(i)->GetName())->Clone();
      }
      if( TString(listEff->At(i)->GetName()).Contains( "_numerator_mctruth_" ) )
      {
        eff_h_n_mctruth = (TH1D*)finEff->Get(listEff->At(i)->GetName())->Clone();
      }
      if( TString(listEff->At(i)->GetName()).Contains( "_numerator_qgd_" ) )
      {
        eff_h_n_qgd = (TH1D*)finEff->Get(listEff->At(i)->GetName())->Clone();
      }
    }
    else
      continue;
  }

  TCanvas *eff_c = new TCanvas("eff_c","A Simple Graph Example",200,10,700,500);
  //eff_c->SetLogy();
  gStyle->SetOptStat(0);

  eff_h_n_normal->GetXaxis()->SetRangeUser(min,max);
  eff_h_n_normal->GetXaxis()->SetTitle(XTitle);
  eff_h_n_normal->GetYaxis()->SetRangeUser(0,1);

  eff_h_n_normal->Divide(eff_h_d);
  eff_h_n_normal->SetLineColor(1);

  eff_h_n_mctruth->GetXaxis()->SetRangeUser(min,max);
  eff_h_n_mctruth->GetXaxis()->SetTitle(XTitle);
  eff_h_n_mctruth->Divide(eff_h_d);
  eff_h_n_mctruth->SetLineColor(2);

  eff_h_n_qgd->GetXaxis()->SetRangeUser(min,max);
  eff_h_n_qgd->GetXaxis()->SetTitle(XTitle);
  eff_h_n_qgd->Divide(eff_h_d);
  eff_h_n_qgd->SetLineColor(3);

  eff_h_n_normal->Draw();
  eff_h_n_mctruth->Draw("same");
  eff_h_n_qgd->Draw("same");

  const std::string titre="CMS Preliminary 2016";
  TLatex *eff_title = new TLatex(0.09770115,0.9194915,titre.c_str());
  eff_title->SetNDC();
  eff_title->SetTextSize(0.045);
  eff_title->Draw("same");

  //Create Legend
  TLegend *eff_leg = new TLegend(0.70,0.75,0.90,0.90);
  eff_leg->SetBorderSize(1);
  eff_leg->SetLineColor(1);
  eff_leg->SetLineWidth(2);
  eff_leg->SetFillColor(0);
  eff_leg->SetTextFont(42);
  eff_leg->SetTextSize(0.03);
  eff_leg->SetHeader("Top Tag Eff");
  eff_leg->AddEntry(eff_h_n_normal,"Normal");
  eff_leg->AddEntry(eff_h_n_mctruth,"MCTruth");
  eff_leg->AddEntry(eff_h_n_qgd,"QGD");
  eff_leg->Draw("same");

  eff_c->SaveAs( target_DIR + TString("/_Eff") + hist_tag + TString(".png") );
  eff_c->SaveAs( target_DIR + TString("/_Eff") + hist_tag + TString(".pdf") );
  eff_c->SaveAs( target_DIR + TString("/_Eff") + hist_tag + TString(".C") );
  return ; 
}

void TopTaggerQGDPlots::MisTagRatePlots(
                                        TString hist_tag,
                                        TString XTitle,
                                        double min,
                                        double max
                                       )
{
  TH1D * mistag_h_d;
  TH1D * mistag_h_n_normal;
  TH1D * mistag_h_n_mctruth;
  TH1D * mistag_h_n_qgd;

  int NHist = listMisTag->GetSize();;

  for(int i  = 0 ; i < NHist ; i++)
  {
    if( TString(listMisTag->At(i)->GetName()).Contains( hist_tag ) )
    {
      if( TString(listMisTag->At(i)->GetName()).Contains( "_denominator_" ) )
      {
        mistag_h_d = (TH1D*)finMisTag->Get(listMisTag->At(i)->GetName())->Clone();
      }
      if( TString(listMisTag->At(i)->GetName()).Contains( "_numerator_normal_" ) )
      {
        mistag_h_n_normal = (TH1D*)finMisTag->Get(listMisTag->At(i)->GetName())->Clone();
      }
      if( TString(listMisTag->At(i)->GetName()).Contains( "_numerator_mctruth_" ) )
      {
        mistag_h_n_mctruth = (TH1D*)finMisTag->Get(listMisTag->At(i)->GetName())->Clone();
      }
      if( TString(listMisTag->At(i)->GetName()).Contains( "_numerator_qgd_" ) )
      {
        mistag_h_n_qgd = (TH1D*)finMisTag->Get(listMisTag->At(i)->GetName())->Clone();
      }
    }
    else
      continue;
  }

  TCanvas *mistag_c = new TCanvas("mistag_c","A Simple Graph Example",200,10,700,500);
  //mistag_c->SetLogy();
  gStyle->SetOptStat(0);

  mistag_h_n_normal->GetXaxis()->SetRangeUser(min,max);
  mistag_h_n_normal->GetXaxis()->SetTitle(XTitle);
  mistag_h_n_normal->GetYaxis()->SetRangeUser(0,1);

  mistag_h_n_normal->Divide(mistag_h_d);
  mistag_h_n_normal->SetLineColor(1);

  mistag_h_n_mctruth->GetXaxis()->SetRangeUser(min,max);
  mistag_h_n_mctruth->GetXaxis()->SetTitle(XTitle);
  mistag_h_n_mctruth->Divide(mistag_h_d);
  mistag_h_n_mctruth->SetLineColor(2);

  mistag_h_n_qgd->GetXaxis()->SetRangeUser(min,max);
  mistag_h_n_qgd->GetXaxis()->SetTitle(XTitle);
  mistag_h_n_qgd->Divide(mistag_h_d);
  mistag_h_n_qgd->SetLineColor(3);

  mistag_h_n_normal->Draw();
  mistag_h_n_mctruth->Draw("same");
  mistag_h_n_qgd->Draw("same");

  const std::string titre="CMS Preliminary 2016";
  TLatex *mistag_title = new TLatex(0.09770115,0.9194915,titre.c_str());
  mistag_title->SetNDC();
  mistag_title->SetTextSize(0.045);
  mistag_title->Draw("same");

  //Create Legend
  TLegend *mistag_leg = new TLegend(0.70,0.75,0.90,0.90);
  mistag_leg->SetBorderSize(1);
  mistag_leg->SetLineColor(1);
  mistag_leg->SetLineWidth(2);
  mistag_leg->SetFillColor(0);
  mistag_leg->SetTextFont(42);
  mistag_leg->SetTextSize(0.03);
  mistag_leg->SetHeader("Top MisTag Rate");
  mistag_leg->AddEntry(mistag_h_n_normal,"Normal");
  mistag_leg->AddEntry(mistag_h_n_mctruth,"MCTruth");
  mistag_leg->AddEntry(mistag_h_n_qgd,"QGD");
  mistag_leg->Draw("same");

  mistag_c->SaveAs( target_DIR + TString("/_MisTagRate") + hist_tag + TString(".png") );
  mistag_c->SaveAs( target_DIR + TString("/_MisTagRate") + hist_tag + TString(".pdf") );
  mistag_c->SaveAs( target_DIR + TString("/_MisTagRate") + hist_tag + TString(".C") );
  return ;
}

struct Plotting_Parameter
{
  TString hist_tag;
  TString XTitle;
  double min;
  double max;
};
