#include "bitmapEditor.h"
#include "bitmap.h"
#include<string>
#include<vector>

using namespace std;

vector<vector<Pixel> > bitmapEditor :: oldTimeyPhoto(void){
  vector<vector<Pixel> > oldTimeyBmp;
  oldTimeyBmp = toPixelMatrix();
  
  return oldTimeyBmp;
}

vector<vector<Pixel> > bitmapEditor :: brightness(void){
  vector<vector<Pixel> > brightBmp;
  brightBmp = toPixelMatrix();

  return brightBmp;
}

vector<vector<Pixel> > bitmapEditor :: warmth(void){
  vector<vector<Pixel> > warmthBmp;
  warmthBmp = toPixelMatrix();

  return warmthBmp;
}

vector<vector<Pixel> > bitmapEditor :: saturation(void){
  vector<vector<Pixel> > saturationBmp;
  saturationBmp = toPixelMatrix();

  return saturationBmp;

}

vector<vector<Pixel> > bitmapEditor :: border(void){
  vector<vector<Pixel> > borderBmp;
  borderBmp = toPixelMatrix();

  return borderBmp;
}
