#include <iostream>
#include <vector>
#include <string>
#include <cmath>

class calculations
{
private:
    double travel_estimation;
    double total_distance;
public:
    calculations()
    {
        std::cout<<"-----------------F15 Eagle II Combat Mission Planner-----------------"<<std::endl;
        ask_for_distance();
    }
    void ask_for_distance()
    {
        double x1;
        double x2;
        double y1;
        double y2;
        std::cout<<"Enter x coordinates of the current location: ";
        std::cin>>x1;
        std::cout<<"Enter y coordinates of the current location: ";
        std::cin>>y1;
        std::cout<<"Enter x coordinates of the target location: ";
        std::cin>>x2;
        std::cout<<"Enter y coordinates of the target location: ";
        std::cin>>y2;
        total_distance = distance(x1,x2,y1,y2);
        std::cout<<"The total distance is: "<<total_distance<<std::endl;
        travel_estimation = travel_time_estimation(total_distance);
        std::cout<<"Total time estimation is: "<<travel_estimation<<" hours"<<std::endl;
        ask_fuel_percentage();
        ask_for_mission_and_range_calculations();

    }

    double distance(double x1,double x2,double y1,double y2)
    {
        return sqrt(pow((x2-x1),2) + pow((y2-y1),2)) * 100;
    }

    double travel_time_estimation(double distance)
    {
        return (distance / 3017.52);
    }
    void ask_fuel_percentage()
    {
        double percentage;
        std::cout<<"Enter current fuel percentage: ";
        std::cin>>percentage;
        if(percentage >= 31) std::cout<<"Rserve fuel percentage is fine"<<std::endl;
        if(percentage < 31) std::cout<<"Reserve fuel percentage is not enough to fly fill until "<< 31 - percentage<<std::endl;
    }


    void ask_for_mission_and_range_calculations()
    {
        int type;
        std::cout<<"Enter 1 for flight time, 2 for air interaction, 3 for air-earth, 4 for dangerous zone: ";
        std::cin>>type;
        switch (type)
        {
            case 1:
                {            
                    // initial weight = average weight of F15 + 4 x AIM-120;
                    // final weight = left fuel weight
                    double m1 = 56000 + (4*348);
                    double m2 = left_fuel_weight(travel_estimation);
                    std::cout<<"Have some AIM-120 for any surprises along the way, God bless you"<<std::endl;
                    double range = (1700/385) * log(m1/m2);
                    if(range > total_distance) 
                    {
                        std::cout<<"You have to stop at or befor"<<(range - 200)<<std::endl;
                    }
                    else if(range < total_distance)
                    {
                        std::cout<<"You have engough fuel for the whole trip, God bless you"<<std::endl;
                    }
                    else if(range == total_distance)
                    {
                        std::cout<<"Your fuel is enough for the entire trip without margin of saftey stop before"<<(range - 100)<<" for refuel"<<std::endl;
                    }
                    break;
                }
            case 2:
                {
                    // initial weight = fuel weight + 12 x 348
                    // final weight = left fuel weight - 9 x 348
                    double m1 = 56000 + (12*348);
                    double m2 = left_fuel_weight(travel_estimation) - (9*348);
                    std::cout<<"The jet need to have AIM-120 AMRAAM missiles"<<std::endl;
                    double range = (1700/385) * log(m1/m2);
                    if(range > total_distance) 
                    {
                        std::cout<<"You have to stop at or befor"<<(range - 200)<<std::endl;
                    }
                    else if(range < total_distance)
                    {
                        std::cout<<"You have engough fuel for the whole trip, God bless you"<<std::endl;
                    }
                    else if(range == total_distance)
                    {
                        std::cout<<"Your fuel is enough for the entire trip without margin of saftey stop before"<<(range - 100)<<" for refuel"<<std::endl;
                    }
                    break;
                }
        
            case 3:
                {
                    // initial weight = fuel weight + 12 x 348
                    // final weight = left fuel weight - 9 x 348
                    double m1 = 56000 + (12*348);
                    double m2 = left_fuel_weight(travel_estimation) - (9*348);
                    std::cout<<"The jet need to have LRASM and RBS-15 and watch out for SAMs"<<std::endl;
                    double range = (1700/385) * log(m1/m2);
                    if(range > total_distance) 
                    {
                        std::cout<<"You have to stop at or befor"<<(range - 200)<<std::endl;
                    }
                    else if(range < total_distance)
                    {
                        std::cout<<"You have engough fuel for the whole trip, God bless you"<<std::endl;
                    }
                    else if(range == total_distance)
                    {
                        std::cout<<"Your fuel is enough for the entire trip without margin of saftey stop before"<<(range - 100)<<" for refuel"<<std::endl;
                    }
                    break;
                }
            case 4:
                {
                    // initial weight = fuel weight + 12 x 348
                    // final weight = left fuel weight - 5 x 348
                    double m1 = 56000 + (12*348);
                    double m2 = left_fuel_weight(travel_estimation) - (5*348);
                    std::cout<<"In such situation make sure to have AIM-120 and LRASM and be careful for SAMs"<<std::endl;
                    double range = (1700/385) * log(m1/m2);
                    if(range > total_distance) 
                    {
                        std::cout<<"You have to stop at or befor"<<(range - 200)<<std::endl;
                    }
                    else if(range < total_distance)
                    {
                        std::cout<<"You have engough fuel for the whole trip, God bless you"<<std::endl;
                    }
                    else if(range == total_distance)
                    {
                        std::cout<<"Your fuel is enough for the entire trip without margin of saftey stop before"<<(range - 100)<<" for refuel"<<std::endl;
                    }
                    break;
                }
            default:
                std::cout<<"You have entered nothing, reload the system"<<std::endl;
                break;
        }
        
    }
    double left_fuel_weight(double time)
    {
        // 17000 max hold
        // 8000 gallon per hour
        return (17000 - (8000 * time));
    }

};

class dataValidation
{
private:
    std::vector<std::string*>pilotIds;
public:
    dataValidation()
    {
        
        std::cout<<"-----------------F15 Eagle II Combat Mission Planner-----------------"<<std::endl;
        std::string id1 = "US2467762";
        std::string id2 = "US2469851";
        std::string id3 = "US2465532";
        std::string id4 = "US2462341";
        std::string id5 = "US2460023";
        pilotIds.emplace_back(&id1);
        pilotIds.emplace_back(&id2);
        pilotIds.emplace_back(&id3);
        pilotIds.emplace_back(&id4);
        pilotIds.emplace_back(&id5);
        ask_id_function();
    }


    void ask_id_function()
    {
        int vector_size = pilotIds.size();
        std::string askId; 
        std::cout<<"Enter you ID: ";
        std::cin>>askId;
        bool valid_data = false;
        bool validId = false;
        for(int i=0;i<vector_size;i++)
        {
            if(askId == *pilotIds[i]) 
            {
                std::cout<<"Welcome soldire"<<std::endl;
                validId = true;
                valid_data = true;
                break;
            }
        }
        if(!validId)
        {
            std::cout<<"Invalid ID no access granted";
        }
        if(valid_data)
        {
            calculations calc;
        }
    }
};

int main()
{
    dataValidation run;
    return 0;
}

