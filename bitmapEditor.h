#ifndef _BITMAPEDIT_H_
#define _BITMAPEDIT_H_
#include<string>
#include<vector>
#include"bitmap.h"

using namespace std;

class bitmapEditor : public Bitmap
{
  private:

  public:
    vector<vector<Pixel> > oldTimeyPhoto (void);
    vector<vector<Pixel> > brightness (void);
    vector<vector<Pixel> > warmth (void);
    vector<vector<Pixel> > saturation (void);

};
#endif
