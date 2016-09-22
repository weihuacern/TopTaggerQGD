#ifndef _TTConstants_H_
#define _TTConstants_H_

//define lumi in pb-1
//2016 Moriond
//#define LUMI 2262.946
//2016 ICHEP
//#define LUMI 8000 //test tag
//#define LUMI 4004.345 //preapp, NTuple v7 fix b working point
//#define LUMI 7647.637518921 //app, NTuple v8
#define LUMI 12918.140703927 //final 2016 ICHEP data set

#define JETSETA_BINS 6
#define JETSPT_BINS 6

//#define NSEARCH_BINS 45
//#define NSEARCH_BINS 37
#define NSEARCH_BINS 59
//#define NSEARCH_BINS 8
const double jetetabins_edge[JETSETA_BINS+1] = {0,1.305,1.392,2.650,3.139,4.7,5.191};
const double jetptbins_edge[JETSPT_BINS+1] = {0,20,40,50,80,100};
#endif
