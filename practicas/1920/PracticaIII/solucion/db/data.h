#ifndef DATA_H
#define DATA_H

#include <vector>
#include "pair.h"

template <class K, class V>
class Data
{
    template<class K, class V> friend std::ostream & operator << (std::ostream & os, Data<fK,fV> const & d);
public:
    Data();
    void insert(Pair<K,V>* p);
    V value(K const & key);
    std::vector<K> getKeys();

private:
    std::vector<Pair <K,V>* > data;
};

template <class K, class V>
Data<K,V>::Data(){
    // nothing to do here
}

template <class K, class V>
void Data<K,V>::insert(Pair<K,V> * p){
    try{
        // if there is no error ir means the key exists in dataset
        value(p->key());
        throw std::string("Key already in dataset");
    }catch(std::string e){
        // if there has been an exception means the key is not present, so insert it
        data.push_back(p);
    }

}

template<class K, class V>
V Data<K,V>::value(const K &key)
{
    for(auto elem: data){
        if(elem->key() == key){
            return elem->value();
        }
    }
    throw std::string{"Key not present in data"};
}

template<class K, class V>
std::vector<K> Data<K,V>::getKeys()
{
    std::vector<K> result;
    for(auto elem: data){
        result.push_back(elem->key());
    }
    return result;
}

template<class K, class V>
std::ostream & operator << (std::ostream & os, Data<K,V> const & d){
    for(auto pair: d.data){
        os << *pair << "\n";
    }

    return os;

}

#endif // DATA_H
