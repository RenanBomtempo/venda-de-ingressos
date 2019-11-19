#include "totem.h"

Totem::Totem(Usuario* us){
    usuario = us;
}

Usuario* Totem::get_usuario(){
    return usuario;
}
