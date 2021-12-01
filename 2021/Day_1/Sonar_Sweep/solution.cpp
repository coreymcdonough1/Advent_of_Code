#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(void)
{
   uint16_t depth;
   uint16_t prev_depth = 0;
   uint16_t sum_increased_depths;
   fstream input_file;   

   input_file.open("input.txt", fstream::in);

   if(!input_file.is_open())
   {
      cout << "Could not open file. Exiting.";
      return 1;
   }

   input_file >> prev_depth;
   while(input_file >> depth)
   {
      if(depth > prev_depth)
         sum_increased_depths++;
      prev_depth = depth;
   }
   input_file.close();

   cout << "Number of measurements larger than previous: " << sum_increased_depths;

   return 0;
}