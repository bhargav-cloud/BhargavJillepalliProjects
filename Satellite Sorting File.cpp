#include <iostream>        
#include <fstream>        
#include <algorithm>    
#include <vector>       
#include <string>
using namespace std;

//---------------------------------------------------------------
// Satellite class 
//
class Satellite
{
  public:
  
    Satellite(string name, string line_1, string line_2) // constructor
    {
        this->name_line = name;
        this->line_1 = line_1;
        this->line_2 = line_2;
    }
    
    //---------------------------------------------------------------
    // accessor methods
    //
    string name() const
    {
        return name_line;
    }
    
    int cat_num() const
    {
        return stoi(line_1.substr(2, 5));
    }
    
    double arg_of_perigee() const
    {
        return stod(line_2.substr(34, 8));
    }
    
    //----------------------------------------------------------------
    // Implement the following two methods
    //
    double inclination() const
    {
        return stod(line_2.substr(9, 6));
    }
    
    double eccentricity() const
    {
        return stod("0." + line_2.substr(26, 7));
    }
 
  private:
  
      string name_line;    
      string line_1;
      string line_2;
};

bool inclin_less(Satellite lhs, Satellite rhs)
    {
        return lhs.inclination() < rhs.inclination();
    }

bool eccen_less(Satellite lhs, Satellite rhs)
    {
        return lhs.eccentricity() < rhs.eccentricity();
    }

//---------------------------------------------------------------
// main (client) program
//
int main()
{
    //---------------------------------------------------------------
    // Satellite vector container
    //
    vector<Satellite> sat_list;
    
    //---------------------------------------------------------------
    // Read Satellite data
    //
    string name;
      string line_1;
      string line_2;
      
    ifstream sat_file ("weather.txt");
    if (sat_file.is_open())
    {
        while ( getline (sat_file, name) )
        {
          getline (sat_file, line_1);
          getline (sat_file, line_2);
          sat_list.push_back(Satellite(name, line_1, line_2));
        }
        sat_file.close();
    }

      else cout << "Unable to open file"; 
    
    //---------------------------------------------------------------
    // Print Weather Satellites
    //
    cout << "\nWeather Satellites:\n-----------------------------------------\n";
    for(Satellite s : sat_list) 
        printf("%8.4f  %5d  %s\n", s.arg_of_perigee(), s.cat_num(), s.name().c_str());
    
    //---------------------------------------------------------------
    // Print Weather Satellites sorted by orbital inclination
    //
    sort(sat_list.begin(), sat_list.end(), inclin_less);
    cout << "\nWeather Satellites Sorted by inclination:\n-----------------------------------------\n";
    for(Satellite s : sat_list)
        printf("%6.2f  %5d  %s\n", s.inclination(), s.cat_num(), s.name().c_str());
    //---------------------------------------------------------------
    // Print Weather Satellites sorted by orbital eccentricity
    //
    sort(sat_list.begin(), sat_list.end(), eccen_less);
    cout << "\nWeather Satellites Sorted by eccentricity:\n-----------------------------------------\n";
    for(Satellite s : sat_list)
        printf("%10.6f  %5d  %s\n", s.eccentricity(), s.cat_num(), s.name().c_str());
    
    string temp;
    cout << "\nPress Enter to Exit"; getline (cin, temp);
    return 0;
}