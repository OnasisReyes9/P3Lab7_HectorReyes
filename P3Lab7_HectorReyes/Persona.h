/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Persona.h
 * Author: Onasis Reyes
 *
 * Created on 27 de noviembre de 2020, 01:24 PM
 */

#include <string>
#include <vector>


#ifndef PERSONA_H
#define PERSONA_H

using std::string;
using std::vector;

class Persona {
public:
    Persona();
    Persona(const Persona& orig);
    Persona(string, string, string, int, int);
    void setNombre(string);
    string getNombre();
    void setApellido(string);
    string getApellido();
    void setPassword(string);
    string getPassword();
    void setLlave(int);
    int getLlave();
    void setPosicion_de_Registro(int);
    int getPosicion_de_Registro();
    string to_string();
    void setMensaje(string);
    string getMensaje(int);
    virtual ~Persona();
public:
    string nombre, apellido, password;
    int llave, pos_en_registro;
    vector <string> mensajes_recibidos;
};

#endif /* PERSONA_H */