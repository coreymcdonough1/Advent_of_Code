#include <iostream>
#include <fstream>
#include <string>
#include <numeric>
#include <list>

using namespace std;

#define WINDOW_SIZE 3
//#define DEBUG

int main(void)
{
   uint16_t depth;
   list<uint16_t> depth_window;
   uint16_t depth_window_sum;
   uint16_t prev_depth_window_sum;

   uint16_t sum_increased_depths = 0;
   fstream input_file;   

   input_file.open("input.txt", fstream::in);

   if(!input_file.is_open())
   {
      cout << "Could not open file. Exiting.";
      return 1;
   }

   // initialize window and first sum
   while(depth_window.size() < WINDOW_SIZE)
   {
      input_file >> depth;
      depth_window.push_back(depth);
   }
   prev_depth_window_sum = accumulate(begin(depth_window), end(depth_window), 0);

   while(input_file >> depth)
   {
      // update window
      depth_window.pop_front();
      depth_window.push_back(depth);
      depth_window_sum = accumulate(begin(depth_window), end(depth_window), 0);

      if(depth_window_sum > prev_depth_window_sum)
      {
         sum_increased_depths++;
      }

      #ifdef DEBUG
         if(depth_window_sum > prev_depth_window_sum)
         {
            cout << depth_window_sum <<" (increased)\n";
         }
         else if (depth_window_sum == prev_depth_window_sum)
         {
            cout << depth_window_sum <<" (no change)\n";
         }
         else
         {
            cout << depth_window_sum <<" (decreased)\n";
         }
      #endif
      
      prev_depth_window_sum = depth_window_sum;
   }
   input_file.close();

   cout << "Number of measurements larger than previous: " << sum_increased_depths;

   return 0;
}