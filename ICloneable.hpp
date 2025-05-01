#ifndef ICLONEABLE_HPP
#define ICLONEABLE_HPP

#include <memory>

template <typename T>
class ICloneable{
    public:
        virtual std::unique_ptr<T> clone() = 0;
        virtual ~ICloneable() = default;
};

#endif