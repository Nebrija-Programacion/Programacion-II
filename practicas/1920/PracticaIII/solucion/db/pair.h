#ifndef PAIR_H
#define PAIR_H
#include <ostream>

template<class K, class V>
class Pair
{
    template<class fK, class fV> friend std::ostream & operator<<(std::ostream & os, Pair<fK,fV> const & p);

    public:
    Pair(K const & k, V const & v);
    V value();
    K key();

private:
    K _key;
    V _value;
};

template<class K, class V>
Pair<K,V>::Pair(K const & k, V const & v){
    _key = k;
    _value = v;
}

template<class K, class V>
V Pair<K,V>::value()
{
    return _value;
}

template<class K, class V>
K Pair<K,V>::key()
{
    return _key;
}
template<class K, class V>
std::ostream & operator<<(std::ostream & os, Pair<K,V> const & p){
    os << p._key << ": " << p._value;
    return os;
}

#endif // PAIR_H
