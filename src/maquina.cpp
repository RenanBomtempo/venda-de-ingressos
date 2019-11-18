#include "maquina.h"

Maquina::Maquina(Usuario* us){
    usuario = us;
}

Usuario* Maquina::get_usuario(){
    return usuario;
}
