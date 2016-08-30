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
  void CompareTemplate(
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

  finEff = TFile::Open("RootForPlotting/TopTaggerEff.root");
  listEff = finEff->GetListOfKeys();
  finMisTag = TFile::Open("RootForPlotting/TopTaggerMisTag.root");
  listMisTag = finMisTag->GetListOfKeys();

  //convert lumi from double pb-1 to string, fb-1
  std::ostringstream strs;
  strs << (4000/1000);
  lumi_str = strs.str();
}

void TopTaggerQGDPlots::PrintPlotsName()
{
  for(int i  = 0 ; i < listEff->GetSize() ; i++)
  {
    std::cout<<"Name: "<< listEff->At(i)->GetName() << "("<< i <<")"<<std::endl;
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
  TH1D * h_qjets;
  TH1D * h_gjets;
  TH1D * h_pjets;

  int NHist = listEff->GetSize();;

  //Get Eff and Pred from root file
  for(int i  = 0 ; i < NHist ; i++)
  {
    if( TString(listEff->At(i)->GetName()).Contains( hist_tag ) )
    {
      if( TString(listEff->At(i)->GetName()).Contains( "_qjets" ) )
      {
        h_qjets = (TH1D*)finEff->Get(listEff->At(i)->GetName())->Clone();
      }
      if( TString(listEff->At(i)->GetName()).Contains( "_gjets" ) )
      {
        h_gjets = (TH1D*)finEff->Get(listEff->At(i)->GetName())->Clone();
      }
      if( TString(listEff->At(i)->GetName()).Contains( "_pjets" ) )
      {
        h_pjets = (TH1D*)finEff->Get(listEff->At(i)->GetName())->Clone();
      }
    }
    else
      continue;
  }

  TCanvas *c = new TCanvas("c","A Simple Graph Example",200,10,700,500);
  //c->SetLogy();
  gStyle->SetOptStat(0);

  h_qjets->GetXaxis()->SetRangeUser(min,max);
  h_qjets->GetXaxis()->SetTitle(XTitle);
  //h_qjets->GetYaxis()->SetRangeUser(1000,10000000);
  h_qjets->SetLineColor(1);

  h_gjets->GetXaxis()->SetRangeUser(min,max);
  h_gjets->GetXaxis()->SetTitle(XTitle);
  h_gjets->SetLineColor(2);

  h_pjets->GetXaxis()->SetRangeUser(min,max);
  h_pjets->GetXaxis()->SetTitle(XTitle);
  h_pjets->SetLineColor(3);

  h_qjets->Draw();
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
  leg->SetHeader("TTJets Inc MC : Jet Type");
  leg->AddEntry(h_qjets,"Quark Jet");
  leg->AddEntry(h_gjets,"Gluon Jet");
  leg->AddEntry(h_pjets,"Pileup Jet");
  leg->Draw("same");

  c->SaveAs( target_DIR + TString("/") + hist_tag + TString(".png") );
  c->SaveAs( target_DIR + TString("/") + hist_tag + TString(".pdf") );
  c->SaveAs( target_DIR + TString("/") + hist_tag + TString(".C") );
  return ;
}

/*
void TopTaggerQGDPlots::CompareTemplate(
                                   TString hist_tag,
                                   TString XTitle,
                                   double min,
                                   double max
                                  )
{ 
  TH1D * h_inverted;
  TH1D * h_normal;

  for(int i  = 0 ; i < list->GetSize() ; i++)
  {
    if( TString(list->At(i)->GetName()).Contains( hist_tag ) )
    {
      if( TString(list->At(i)->GetName()).Contains( "_inverted_" ) )
      {
        h_inverted = (TH1D*)fin->Get(list->At(i)->GetName())->Clone();
      }
      if( TString(list->At(i)->GetName()).Contains( "_exp_" ) )
      {
        h_normal = (TH1D*)fin->Get(list->At(i)->GetName())->Clone();
      }
    }
    else
      continue;
  }

  TCanvas *c = new TCanvas("c","A Simple Graph Example",200,10,700,500); 
  gStyle->SetOptStat(0);

  h_inverted->GetXaxis()->SetRangeUser(min,max);
  h_inverted->GetXaxis()->SetTitle(XTitle);
  h_inverted->SetLineColor(1);
  h_inverted->SetLineWidth(3);
  h_inverted->Sumw2();

  h_normal->GetXaxis()->SetRangeUser(min,max);
  h_normal->GetXaxis()->SetTitle(XTitle);
  h_normal->SetLineColor(2);
  h_normal->SetLineWidth(3);
  h_normal->Sumw2();

  h_inverted->Draw(); 
  h_normal->Draw("same");

  const std::string titre="CMS Preliminary 2015, 3 fb^{-1}, #sqrt{s} = 13 TeV";
  TLatex *title = new TLatex(0.09770115,0.9194915,titre.c_str());
  title->SetNDC();
  title->SetTextSize(0.045);
  title->Draw("same");

  TLegend* leg = new TLegend(0.6,0.75,0.85,0.85);
  leg->SetBorderSize(0);
  leg->SetTextFont(42);
  leg->SetFillColor(0);
  leg->AddEntry(h_normal,"Normal","l");
  leg->AddEntry(h_inverted,"Inverted Delat Phi","l");
  leg->Draw("same");

  c->SaveAs( hist_tag + TString("_normal_inverted.png") );
  c->SaveAs( hist_tag + TString("_normal_inverted.pdf") );
  c->SaveAs( hist_tag + TString("_normal_inverted.C") );
  return ;
}
*/

void TopTaggerQGDPlots::MisTagRatePlots(
                                        TString hist_tag,
                                        TString XTitle,
                                        double min,
                                        double max
                                       )
{
  TH1D * h_d;
  TH1D * h_n_normal;
  TH1D * h_n_mctruth;
  TH1D * h_n_qgd;

  int NHist = listMisTag->GetSize();;

  for(int i  = 0 ; i < NHist ; i++)
  {
    if( TString(listMisTag->At(i)->GetName()).Contains( hist_tag ) )
    {
      if( TString(listMisTag->At(i)->GetName()).Contains( "_denominator_" ) )
      {
        h_d = (TH1D*)finMisTag->Get(listMisTag->At(i)->GetName())->Clone();
      }
      if( TString(listMisTag->At(i)->GetName()).Contains( "_numerator_normal_" ) )
      {
        h_n_normal = (TH1D*)finMisTag->Get(listMisTag->At(i)->GetName())->Clone();
      }
      if( TString(listMisTag->At(i)->GetName()).Contains( "_numerator_mctruth_" ) )
      {
        h_n_mctruth = (TH1D*)finMisTag->Get(listMisTag->At(i)->GetName())->Clone();
      }
      if( TString(listMisTag->At(i)->GetName()).Contains( "_numerator_qgd_" ) )
      {
        h_n_qgd = (TH1D*)finMisTag->Get(listMisTag->At(i)->GetName())->Clone();
      }
    }
    else
      continue;
  }

  TCanvas *c = new TCanvas("c","A Simple Graph Example",200,10,700,500);
  //c->SetLogy();
  gStyle->SetOptStat(0);

  h_n_normal->GetXaxis()->SetRangeUser(min,max);
  h_n_normal->GetXaxis()->SetTitle(XTitle);
  h_n_normal->GetYaxis()->SetRangeUser(0,1);

  h_n_normal->Divide(h_d);
  h_n_normal->SetLineColor(1);

  h_n_mctruth->GetXaxis()->SetRangeUser(min,max);
  h_n_mctruth->GetXaxis()->SetTitle(XTitle);
  h_n_mctruth->Divide(h_d);
  h_n_mctruth->SetLineColor(2);

  h_n_qgd->GetXaxis()->SetRangeUser(min,max);
  h_n_qgd->GetXaxis()->SetTitle(XTitle);
  h_n_qgd->Divide(h_d);
  h_n_qgd->SetLineColor(3);

  h_n_normal->Draw();
  h_n_mctruth->Draw("same");
  h_n_qgd->Draw("same");

  const std::string titre="CMS Preliminary 2016";
  TLatex *title = new TLatex(0.09770115,0.9194915,titre.c_str());
  title->SetNDC();
  title->SetTextSize(0.045);
  title->Draw("same");

  //Create Legend
  TLegend* leg = new TLegend(0.70,0.75,0.90,0.90);
  leg->SetBorderSize(1);
  leg->SetLineColor(1);
  leg->SetLineWidth(2);
  leg->SetFillColor(0);
  leg->SetTextFont(42);
  leg->SetTextSize(0.03);
  leg->SetHeader("Top MisTag Rate");
  leg->AddEntry(h_n_normal,"Normal");
  leg->AddEntry(h_n_mctruth,"MCTruth");
  leg->AddEntry(h_n_qgd,"QGD");
  leg->Draw("same");

  c->SaveAs( target_DIR + TString("/_MisTagRate") + hist_tag + TString(".png") );
  c->SaveAs( target_DIR + TString("/_MisTagRate") + hist_tag + TString(".pdf") );
  c->SaveAs( target_DIR + TString("/_MisTagRate") + hist_tag + TString(".C") );

  return ;
}

struct Plotting_Parameter
{
  TString hist_tag;
  TString XTitle;
  double min;
  double max;
};
