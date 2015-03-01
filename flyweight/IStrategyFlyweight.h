#ifndef ISTRATEGYFLYWEIGHT_H_INCLUDED
#define ISTRATEGYFLYWEIGHT_H_INCLUDED

#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/matrix_proxy.hpp>

namespace ublas = boost::numeric::ublas;

enum StrategyTag {
    ZeroStrategyTag = 0,
    OneStrategyTag,
    EyeStrategyTag,
    SizeStrategyTag
};


class IStrategyFlyweight {
public:
    ublas::vector<double> operator()(
        ublas::vector<double> vec) const
    {
        return apply(vec);
    }

private:
    virtual ublas::vector<double> apply(
        ublas::vector<double> vec) const = 0;
};

class ZeroStrategy : public IStrategyFlyweight {
public:
    ZeroStrategy(std::size_t size)
    : _mat(ublas::zero_matrix<double>(size))
    {
    }
                
private:
    virtual ublas::vector<double> apply(
        ublas::vector<double> vec) const
    {
        return ublas::prod(
            ublas::project(_mat, 
                ublas::range(0, vec.size()), ublas::range(0, vec.size())),
            vec);
    }

    ublas::matrix<double> _mat;
};

class OneStrategy : public IStrategyFlyweight {
public:
    OneStrategy(std::size_t size)
    : _mat(ublas::matrix<double>(size, size, 1.0))
    {
    }
                
private:
    virtual ublas::vector<double> apply(
        ublas::vector<double> vec) const
    {
        return ublas::prod(
            ublas::project(_mat, 
                ublas::range(0, vec.size()), ublas::range(0, vec.size())),
            vec);
    }

    ublas::matrix<double> _mat;
};

class EyeStrategy : public IStrategyFlyweight {
public:
    EyeStrategy(std::size_t size)
    : _mat(ublas::identity_matrix<double>(size))
    {
    }
                
private:
    virtual ublas::vector<double> apply(
        ublas::vector<double> vec) const
    {
        return ublas::prod(
            ublas::project(_mat, 
                ublas::range(0, vec.size()), ublas::range(0, vec.size())),
            vec);
    }

    ublas::matrix<double> _mat;
};
#endif // ISTRATEGYFLYWEIGHT_H_INCLUDED
