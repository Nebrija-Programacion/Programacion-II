#ifndef NUMEROPOSITIVO_H
#define NUMEROPOSITIVO_H


class NumeroPositivo
{
public:
    NumeroPositivo(float n);

    float getNum() const;
    void setNum(float value);
    float divideBy(float other);
    float multiplyBy(float other);
    float add(float other);

private:
    float num;
};

#endif // NUMEROPOSITIVO_H
