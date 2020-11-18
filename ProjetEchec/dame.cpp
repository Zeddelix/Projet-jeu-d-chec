#include "dame.h"


namespace chest {

dame::~dame() {}

 bool dame::PeutDeplacer(Plateau p,case dep, cas arr)
 {
    return fou::PeutDeplacer(p,dep,arr) || tour::PeutDeplacer(p,dep,arr);
 }


}
