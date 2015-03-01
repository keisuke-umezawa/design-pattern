#ifndef STRATEGYFACTORY_H_INCLUDED
#define STRATEGYFACTORY_H_INCLUDED

#include <vector>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include "IStrategyFlyweight.h"

class StrategyFactory {
public:
    StrategyFactory(const std::size_t maxSize)
    : _maxSize(maxSize), _ptrStrategyFlyweights(SizeStrategyTag)
    {
    }

    IStrategyFlyweight& createStrategyFlyweight(
        StrategyTag tag)
    {
        if (!_ptrStrategyFlyweights[tag]) {
            _ptrStrategyFlyweights[tag] = makeStrtegyFlyweight(tag);
        }
        return *(_ptrStrategyFlyweights[tag]);
    }

private:
    boost::shared_ptr<IStrategyFlyweight> makeStrtegyFlyweight(
        StrategyTag tag) const
    {
        if (tag == ZeroStrategyTag) {
            return boost::make_shared<ZeroStrategy>(_maxSize);
        }
        if (tag == OneStrategyTag) {
            return boost::make_shared<OneStrategy>(_maxSize);
        }
        if (tag == EyeStrategyTag) {
            return boost::make_shared<EyeStrategy>(_maxSize);
        }
        return _ptrStrategyFlyweights[tag];
    }

private:
    const std::size_t _maxSize;
    std::vector<boost::shared_ptr<IStrategyFlyweight> > _ptrStrategyFlyweights;
};

#endif // STRATEGYFACTORY_H_INCLUDED
