#ifndef TABLE_H
#define TABLE_H

#include <map>

#include <mesa.h>

#include "cards.h"

class OneSuitTable : public p3::MesaBasica<OneSuitCard>
{
public:

    using p3::MesaBasica<OneSuitCard>::MesaBasica;

    OneSuitTable();

    void set_images(std::map<OneSuitCard, std::string> front_images , std::string back_image);
};

#endif // TABLE_H
