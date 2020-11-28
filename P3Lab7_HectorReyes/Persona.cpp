/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Persona.cpp
 * Author: Onasis Reyes
 * 
 * Created on 27 de noviembre de 2020, 01:24 PM
 */

#include "Persona.h"

Persona::Persona() {
}

Persona::Persona(string nombre, string apellido, string password, int llave, int pos_en_registro) {
    this -> nombre = nombre;
    this -> apellido = apellido;
    this -> password = password;
    this -> llave = llave;
    this -> pos_en_registro = pos_en_registro;
}

Persona::Persona(const Persona& orig) {
}

Persona::~Persona() {
}

void Persona::setNombre(string nombre) {
    this -> nombre = nombre;
}

string Persona::getNombre() {
    return nombre;
}

void Persona::setApellido(string apellido) {
    this -> apellido = apellido;
}

string Persona::getApellido() {
    return apellido;
}

void Persona::setPassword(string password) {
    this -> password = password;
}

string Persona::getPassword() {
    return password;
}

void Persona::setLlave(int llave) {
    this -> llave = llave;
}

int Persona::getLlave() {
    return llave;
}

int Persona::getPosicion_de_Registro() {
    return pos_en_registro;
}

void Persona::setPosicion_de_Registro(int pos_de_registro) {
    this -> pos_en_registro = pos_de_registro;
}

void Persona::setMensaje(string mensaje){
    mensajes_recibidos.push_back(mensaje);
}

string Persona::getMensaje(int posicion){
    return mensajes_recibidos.at(posicion);
}

string Persona::to_string() {
    //string nombre_persona = nombre << apellido << "\n";
    return nombre + " " + apellido + "\n";
}