#include <iostream>

using namespace std;

struct Location
{
    float latitude;
    float longitude;
};

struct RegionChecker
{
    bool isInRegion(Location test) const
    {
        if ((test.latitude >= 47.491683) && (test.latitude <= 47.731835) && (test.longitude >= -122.417678) && (test.longitude <= -122.271341))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

struct PartionResult
{
    int dynamicSize1;
    int dynamicSize2;

    Location *inRegion = new Location[dynamicSize1];
    Location *outRegion = new Location[dynamicSize2];
};

PartionResult partition(Location *arr, int len, const RegionChecker &test)
{
    int inside = 0;
    int outside = 0;
    PartionResult results;
    for (int i = 0; i < len; i++)
    {
        if(test.isInRegion(arr[i]))
        {
            inside++;
            results.dynamicSize1 = inside;
            results.inRegion[inside - 1] = arr[i];
        }
        else
        {
            outside++;
            results.dynamicSize2 = outside;
            results.outRegion[outside - 1] = arr[i];
        }
    }
    return results;
}

int main()
{
    return 0;
}