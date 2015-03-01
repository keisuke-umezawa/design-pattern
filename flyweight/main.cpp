#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/io.hpp>
#include "StrategyFactory.h"
#include "IStrategyFlyweight.h"

int main(int argc, char** argv) {

    const std::size_t maxSize = 1000;
    const ublas::vector<double> vec(100, 1.0);
    const ublas::vector<double> vec1(500, 1.0);

    StrategyFactory factory(maxSize);

    std::cout 
        << factory.createStrategyFlyweight(ZeroStrategyTag)(vec)
        << std::endl;
        
    std::cout 
        << factory.createStrategyFlyweight(OneStrategyTag)(vec)
        << std::endl;

    std::cout 
        << factory.createStrategyFlyweight(OneStrategyTag)(vec1)
        << std::endl;

    std::cout 
        << factory.createStrategyFlyweight(EyeStrategyTag)(vec1)
        << std::endl;

    return 0;
}
