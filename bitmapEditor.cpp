#include "bitmapEditor.h"
#include "bitmap.h"
#include<string>
#include<vector>
#include<ctime>
#include<iostream>

using namespace std;

vector<vector<Pixel> > bitmapEditor :: oldTimeyPhoto(void){
  vector<vector<Pixel> > oldTimeyBmp;
  Pixel rgb;
  char choiceGrain;
  int amtGrain;
  oldTimeyBmp = toPixelMatrix();
  cout << "Would you like to add grain to the photo? (Y/N)?" << endl;
  cin >> choiceGrain;
  if(choiceGrain == 'y' || choiceGrain == 'Y')
  {
    cout << "How much grain would you like to add? (0-100%)?" << endl;
    cin >> amtGrain;
  }
  for (int row = 0; row < oldTimeyBmp.size(); row++)
  {
    for (int col = 0; col < oldTimeyBmp[row].size(); col++)
    {
      rgb = oldTimeyBmp[row][col];
      int sum = rgb.red + rgb.green + rgb.blue;
      int avg = sum / 3;
      if (choiceGrain == 'y' || choiceGrain == 'y')
      {
        int grain;
        grain = ( rand() % amtGrain);
        grain = grain * 2.55;
        avg = avg + grain;
        if(avg > 255)
        {
          avg = 255;
        }
      }
      rgb.red = avg;
      rgb.green = avg;
      rgb.blue = avg;
      oldTimeyBmp[row][col] = rgb;
    }
  }
  return oldTimeyBmp;
}

vector<vector<Pixel> > bitmapEditor :: brightness(void){
  vector<vector<Pixel> > brightBmp;
  int amtBright;
  Pixel rgb;
  brightBmp = toPixelMatrix();
  cout << "How mcuh brightness would you like to add to the photo? (0-100%)" << endl;
  cin >> amtBright;
  for(int row = 0; row < brightBmp.size(); row++)
  {
    for(int col = 0; col < brightBmp[row].size(); col++)
    {
      rgb = brightBmp[row][col];
      int bright;
      bright = amtBright * 2.55;
      rgb.red = rgb.red + bright;
      if(rgb.red > 255)
      {
        rgb.red = 255;
      }
      rgb.green = rgb.green + bright;
      if(rgb.green > 255)
      {
        rgb.green = 255;
      }
      rgb.blue = rgb.blue + bright;
      if(rgb.blue > 255)
      {
        rgb.blue = 255;
      }
      brightBmp[row][col] = rgb;
    }
  }

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
