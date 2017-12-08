#include "bitmapEditor.h"
#include "bitmap.h"
#include<string>
#include<vector>
#include<ctime>
#include<iostream>

using namespace std;

int getSum(int, int, int);

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
      int sum = getSum(rgb.red, rgb.green, rgb.blue);
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
  Pixel rgb;
  char warmthChoice;
  warmthBmp = toPixelMatrix();
  cout << "Warmth allows you to add a red or blue hue to your photo. Type (R) for red hue, type (B) for blue hue" << endl;
  cin >> warmthChoice;
  if(warmthChoice != 'r' && warmthChoice != 'R' && warmthChoice != 'b' && warmthChoice != 'B')
  {
    do{
      cout << warmthChoice << " is not not a valid responce, please enter (R) for red, or (B) for blue. " << endl;
      cin >> warmthChoice;
    }while(warmthChoice != 'r' && warmthChoice != 'R' && warmthChoice != 'b' && warmthChoice != 'B');
  }
  if(warmthChoice == 'r' || warmthChoice == 'R')
  {
    int amtRed;
    cout << "How much red would you like to add? (0-100%)" << endl;
    cin >> amtRed;
    int redness = amtRed * 2.55;
    for(int row = 0; row < warmthBmp.size(); row++)
    {
      for(int col = 0; col < warmthBmp[row].size(); col++)
      {
        rgb = warmthBmp[row][col];
        rgb.red = rgb.red + redness;
        if(rgb.red > 255)
        {
          rgb.red = 255;
        }
        warmthBmp[row][col] = rgb;
      }
    }
  }
  if(warmthChoice == 'b' || warmthChoice == 'B')
  {
    int amtBlue;
    cout << "How much blue would you like to add? (0-100%)" << endl;
    cin >> amtBlue;
    int blueness = amtBlue * 2.55;
    for(int row=0; row < warmthBmp.size(); row++)
    {
      for(int col = 0; col < warmthBmp[row].size(); col++)
      {
        rgb = warmthBmp[row][col];
        rgb.blue = rgb.blue + blueness;
        if(rgb.blue > 255)
        {
          rgb.blue = 255;
        }
        warmthBmp[row][col] = rgb;
      }
    }
  }
  return warmthBmp;
}

vector<vector<Pixel> > bitmapEditor :: saturation(void){
  vector<vector<Pixel> > saturationBmp;
  Pixel rgb;
  double amtSat;
  double sat;
  saturationBmp = toPixelMatrix();
  cout << "How much saturation would you like to add? (0-100%)" << endl;
  cin >> amtSat;
  sat = amtSat / 100;
  for(int row = 0; row < saturationBmp.size(); row++)
  {
    for(int col = 0; col < saturationBmp[row].size(); col++)
    {
      rgb = saturationBmp[row][col];
      rgb.red = rgb.red + (rgb.red * sat);
      if(rgb.red > 255)
      {
        rgb.red = 255;
      }
      rgb.green = rgb.green + (rgb.green * sat);
      if(rgb.green > 255)
      {
        rgb.green = 255;
      }
      rgb.blue = rgb.blue + (rgb.blue * sat);
      if(rgb.blue > 255)
      {
        rgb.blue = 255;
      }
      saturationBmp[row][col] = rgb;
    }
  }
  return saturationBmp;
}

int getSum(int r, int g, int c)
{
    int s = r + g + c;
    return s;
}

