/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Onasis Reyes
 *
 * Created on 27 de noviembre de 2020, 01:15 PM
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <valarray>

#include "Persona.h"

using namespace std;

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

bool usuario_existe(string, string, vector<Persona>);
void mensajes(int, vector<Persona>);
void listar_personas(vector<Persona>);
void ver_mi_llave(int, vector<Persona>);
int mi_pos_en_registro(string, string, vector<Persona>);
string cifrar_o_decifrar_mensaje(string, string, int, bool);
void enviar_mensaje(string, int, vector<Persona>);

/*
 * 
 */

int main(int argc, char** argv) {
    vector <Persona> registro_personas;
    int tamaño_vector = 0;
    bool continuar = true;
    int opcion = 0;
    while (continuar) {
        cout << "---Menú---\n"
                "0. Salir\n"
                "1. Registrarse\n"
                "2. Ingresar\n"
                "-> Escoja su opción: ";
        cin >> opcion;
        cout << endl;
        switch (opcion) {
            case 1:
            {
                string nombre_registar = "", apellido_registrar = "", password_registrar = "";
                int llave = 0;
                srand(time(NULL));
                cout << "---Registro---" << endl;
                cout << "Ingrese nombre: ";
                cin >> nombre_registar;
                cout << "Ingrese apellido: ";
                cin >> apellido_registrar;
                cout << "Ingrese clave: ";
                cin >> password_registrar;
                llave = (std::rand() % 15) + 1;
                Persona persona_nueva
                        (nombre_registar, apellido_registrar, password_registrar, llave, tamaño_vector);
                registro_personas.push_back(persona_nueva);
                tamaño_vector++;
                break;
            }
            case 2:
            {
                string nombre_ingresar = "", password_ingresar = "";
                cout << "---Ingresar---" << endl;
                cout << "Ingrese nombre: ";
                cin >> nombre_ingresar;
                cout << "Ingrese clave: ";
                cin >> password_ingresar;
                if (usuario_existe(nombre_ingresar, password_ingresar, registro_personas)) {
                    int posicion_en_registro =
                            mi_pos_en_registro(nombre_ingresar, password_ingresar, registro_personas);
                    mensajes(posicion_en_registro, registro_personas);
                } else {
                    cout << "Usuario inexistente.";
                }
                break;
            }
            case 0:
            {
                cout << "Fin de la ejecución";
                continuar = false;
                break;
            }
            default:
            {
                cout << "Opción inexistente." << endl;
            }
        }//fin switch
        cout << endl;
    }//fin while
    return 0;
}//fin main

void mensajes(int pos_en_registro, vector <Persona> registro_personas) {
    bool continuar = true;
    int opcion = 0;
    while (continuar) {
        cout << "---Mensajes---\n"
                "0. Salir"
                "1. Enviar Mensaje\n"
                "2. Ver Mensajes Recibidos\n"
                "3. Ver mi llave\n"
                "-> Seleccione que desea hacer: ";
        cin >> opcion;
        cout << endl;
        switch (opcion) {
            case 1:
            {
                cout << "---Lista-de-Personas---";
                listar_personas(registro_personas);
                cout << endl;
                string mensaje = "", mensaje_encriptado = "";
                bool direccion_de_encriptacion = true;
                int llave = ((Persona) registro_personas.at(pos_en_registro)).getLlave();
                int destinatario = 0;
                cout << "Ingrese la posicion en registro del destinatario: ";
                cin >> destinatario;
                cout << "Ingrese el mensaje que desea enviar";
                cin >> mensaje;
                //encripto el mensaje
                mensaje_encriptado = cifrar_o_decifrar_mensaje(
                        mensaje, mensaje_encriptado, llave, direccion_de_encriptacion);
                //envío el mensaje
                enviar_mensaje(mensaje_encriptado, llave, registro_personas);
                break;
            }
            case 2:
            {
                cout << "---Mensajes-Recibidos---" << endl;
                for (int i = 0; i < ((Persona) registro_personas.at(pos_en_registro)).getMensaje(i).size(); i++) {
                    cout << ((Persona) registro_personas.at(pos_en_registro)).getMensaje(i) << endl;
                }
                break;
            }
            case 3:
            {
                ver_mi_llave(pos_en_registro, registro_personas);
                break;
            }
            case 0:
            {
                cout << "Saliendo de mensajes.";
                continuar = false;
                break;
            }
            default:
            {
                cout << "Opción inexistente.";
            }
        }//fon switch
        cout << endl;
    }//fin while
}//fin método

bool usuario_existe(string nombre, string password, vector<Persona> registro_personas) {
    for (int i = 0; i < registro_personas.size(); i++) {
        if (((Persona) registro_personas.at(i)).getNombre() == nombre
                && ((Persona) registro_personas.at(i)).getPassword() == password) {
            return true;
        }//fin if
    }//fin for
    return false;
}//fin método

void listar_personas(vector<Persona> registro_personas) {
    for (int i = 0; i < registro_personas.size(); i++) {
        cout << i << ". ";
        ((Persona) registro_personas.at(i)).to_string();
    }//fin for
}//fin método

void ver_mi_llave(int pos_en_registro, vector<Persona> registro_personas) {
    cout << "Mi llave es: " << ((Persona) registro_personas.at(pos_en_registro)).getLlave();
}//fin método

int mi_pos_en_registro(string nombre, string password, vector<Persona> registro_personas) {
    int posicion = 0;
    for (int i = 0; i < registro_personas.size(); i++) {
        if (((Persona) registro_personas.at(i)).getNombre() == nombre
                && ((Persona) registro_personas.at(i)).getPassword() == password) {
            posicion = ((Persona) registro_personas.at(i)).getPosicion_de_Registro();
        }//fin if
    }//fin if
    return posicion;
}//fin método

string cifrar_o_decifrar_mensaje(string mensaje, string mensaje_cesar, int llave, bool direccion_de_encriptacion) {
    if (llave == 0) {
        return mensaje_cesar;
    } else {
        for (int i = 0; i < mensaje.size(); i++) {
            for (int j = 0; j < 256; j++) {
                if (mensaje[i] == j) {
                    int pos_de_encriptacion = j;
                    if (direccion_de_encriptacion) {
                        direccion_de_encriptacion = false;
                        //en este for encripto la letra hacia adelante
                        for (int k = 0; k < llave; k++) {
                            pos_de_encriptacion++;
                            if (pos_de_encriptacion > 255) {
                                pos_de_encriptacion = 0;
                            }//fin if
                        }//fin for
                        char letra_encriptada = pos_de_encriptacion;
                        mensaje_cesar = mensaje_cesar + letra_encriptada;
                    } else {
                        direccion_de_encriptacion = true;
                        //en este for encripto la letra hacia atras
                        for (int k = 0; k < llave; k++) {
                            pos_de_encriptacion--;
                            if (pos_de_encriptacion < 0) {
                                pos_de_encriptacion = 255;
                            }//fin if
                        }//fin for
                        char letra_encriptada = pos_de_encriptacion;
                        mensaje_cesar = mensaje_cesar + letra_encriptada;
                    }//fin else
                }//fin if
            }//fin for
        }//fin for
    }//fin for
    llave--;
    return cifrar_o_decifrar_mensaje(mensaje, mensaje_cesar, llave, direccion_de_encriptacion);
}//fin método

void enviar_mensaje(string mensaje_encriptado, int pos_destinatario, vector <Persona> registro_personas) {
    ((Persona) registro_personas.at(pos_destinatario)).setMensaje(mensaje_encriptado);
}//fin método