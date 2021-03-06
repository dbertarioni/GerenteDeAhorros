// GerenteDeAhorros.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include<string.h>
#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

#using <mscorlib.dll>
#using <System.dll>
#using <System.Data.dll>
#using <System.Xml.dll>

using namespace System;
using namespace System::Data;
using namespace System::Data::SqlClient;


int opcion;
int contador;
int a;
int menuPrincipal(void);
int menuGruposDeAhorro(void);
int menuSocios(void);
int menuAhorro(void);
int menuPlanesDeAhorro(void);
int menuGeneracionDeEstadosDeCuenta(void);
int menuRegistrarAhorro(void);

void getConnected(void);

using namespace std;
class socio {
public:
	int  IdSocio;
	char Nombre[50];
	char Apellido1[50];
	char Apellido2[50];
	char TelefonoCasa[20];
	char Celular[20];
	char Email[50];
	int  IdGrupo;
public: void ingresarSocio();
};

class grupo {
public:
	int  IdGrupo;
	char NombreGrupo[50];
	time_t FechaCreacion;
public: void ingresarGrupo();
};

class plan {
public:
	int  IdPlan;
	char NombrePlan[50];
	char Descripcion[50];
	int Plazo;
	int Cuota;
	time_t FechaInicial;
	time_t FechaFinal;
	int  Periodicidad;
public: void ingresarPlan();
};

class ahorro {
public:
	int  IdAhorro;
	int  IdSocio;
	time_t Fecha;
	int  Cuota;
	char Estado[50];

public: void ingresarAhorro();
};


char cmp[40];//Dato para comparar cadenas en busquedas
int main()
{
	contador = 0;
	a = 0;
	system("cls");

	getConnected();
	int opcionMenu;
	opcionMenu = menuPrincipal();
	printf("Selecione una opcion del menu #%d\n", opcionMenu);
	printf("\n");
	return 0;
}

int menuPrincipal()
{
	system("cls");
	int opcionMenu;
	int new_opcionMenu;
	char sNum[20];
	do {
		//Display menu
		cout << "/*************************Menu****************************/" << endl;
		cout << "1) Grupos" << endl;
		cout << "2) Socios." << endl;
		cout << "3) Ahorro." << endl;
		cout << "4) Credito." << endl;
		cout << "5) Salir." << endl;
		cout << "Por favor selecione una opcion: ";
		cin >> sNum; //Get user input
		opcionMenu = atoi(sNum);
		if (opcionMenu != 0)
		{
			switch (opcionMenu) {
			case 1: //Do something
				menuGruposDeAhorro();
				return 1;
				break;
			case 2: //Do something else
				menuSocios();
				//Blah blah blah
				return 2;
				break;
			case 3: //Do something else
				menuAhorro();
				//Blah blah blah
				return 3;
				break;
			case 4: //Do something else
				menuPlanesDeAhorro();
				//Blah blah blah
				return 4;
				break;
			case 5: //Exits program
				return 0;
				break;
			default:
				cout << "Seleccione una opcion ente 1 y 5: ";
				cin >> new_opcionMenu;
				opcionMenu = new_opcionMenu;
				break;
			}
		}
		else
		{
			printf("La opcion selecionada no es un numero\n");
			menuPrincipal();
		}
	} while (opcionMenu != 0);
}

int menuGruposDeAhorro()
{
	grupo Grupo;
	system("cls");
	int opcionMenu;
	int new_opcionMenu;
	char sNum[20];
	do {
		//Display menu
		cout << "/*************************Grupos**************************/" << endl;
		cout << "1) Lista de grupo" << endl;
		cout << "2) Crear grupos de ahorro" << endl;
		cout << "3) Modificar grupos de ahorro" << endl;
		cout << "4) Eliminar grupos de ahorro" << endl;
		cout << "5) Volver a menu principal" << endl;
		cout << "Por favor selecione una opcion: ";
		cin >> sNum; //Get user input
		opcionMenu = atoi(sNum);
		if (opcionMenu != 0)
		{
			switch (opcionMenu) {
			case 1: //Do something
					//Blah blah blah
				return 1;
				break;
			case 2: //Do something else
				Grupo.ingresarGrupo();
				return 2;
				break;
			case 3: //Do something else
					//Blah blah blah
				return 3;
				break;
			case 4: //Exits program
				return 0;
				break;
			case 5: //Exits program
				menuPrincipal();
				return 0;
				break;
			default:
				cout << "Seleccione una opcion ente 1 y 5: ";
				cin >> new_opcionMenu;
				opcionMenu = new_opcionMenu;
				break;
			}
		}
		else
		{
			printf("La opcion selecionada no es un numero\n");
			menuGruposDeAhorro();
		}
	} while (opcionMenu != 0);
}

int menuSocios()
{
	system("cls");
	socio Socio;
	int opcionMenu;
	int new_opcionMenu;
	char sNum[20];
	do {
		//Display menu
		cout << "/*************************Socios**************************/" << endl;
		cout << "1) Ver socios" << endl;
		cout << "2) Crear socios" << endl;
		cout << "3) Modificar socios" << endl;
		cout << "4) Eliminar socios" << endl;
		cout << "5) Volver a menu principal" << endl;
		cout << "Por favor selecione una opcion: ";
		cin >> sNum; //Get user input
		opcionMenu = atoi(sNum);
		if (opcionMenu != 0)
		{
			switch (opcionMenu) {
			case 1: //Do something
					//Blah blah blah
				return 1;
				break;
			case 2: //Do something else
				Socio.ingresarSocio();
				return 2;
				break;
			case 3: //Do something else
					//Blah blah blah
				return 3;
				break;
			case 4: //Exits program
				return 0;
				break;
			case 5: //Exits program
				menuPrincipal();
				return 0;
				break;
			default:
				cout << "Seleccione una opcion ente 1 y 5: ";
				cin >> new_opcionMenu;
				opcionMenu = new_opcionMenu;
				break;
			}
		}
		else
		{
			printf("La opcion selecionada no es un numero\n");
			menuSocios();
		}
	} while (opcionMenu != 0);
}

int menuAhorro()
{
	system("cls");
	ahorro Ahorro;
	int opcionMenu;
	int new_opcionMenu;
	char sNum[20];
	do {
		//Display menu
		cout << "/*************************Ahorro**************************/" << endl;
		cout << "1) Planes de ahorro" << endl;
		cout << "2) Registrar ahorro" << endl;
		cout << "3) Estado de cuenta" << endl;
		cout << "4) Volver a menu principal" << endl;
		cout << "Por favor selecione una opcion: ";
		cin >> sNum; //Get user input
		opcionMenu = atoi(sNum);
		if (opcionMenu != 0)
		{
			switch (opcionMenu) {
			case 1: //Do something
				menuPlanesDeAhorro();
				//Blah blah blah
				return 1;
				break;
			case 2: //Do something else
				menuRegistrarAhorro();
				//Blah blah blah
				return 2;
				break;
			case 3: //Do something else
				menuGeneracionDeEstadosDeCuenta();
				//Blah blah blah
				return 3;
				break;
			case 4: //Exits program
				menuPrincipal();
				break;
			default:
				cout << "Seleccione una opcion ente 1 y 4: ";
				cin >> new_opcionMenu;
				opcionMenu = new_opcionMenu;
				break;
			}
		}
		else
		{
			printf("La opcion selecionada no es un numero\n");
			menuAhorro();
		}
	} while (opcionMenu != 0);
}

int menuPlanesDeAhorro()
{
	system("cls");
	plan Plan;
	int opcionMenu;
	int new_opcionMenu;
	char sNum[20];
	do {
		//Display menu
		cout << "/*************************Planes de ahorro**************************/" << endl;
		cout << "1) Nuevo plan" << endl;
		cout << "2) Listar planes" << endl;
		cout << "3) Volver a menu ahorro" << endl;
		cout << "Por favor selecione una opcion: ";
		cin >> sNum; //Get user input
		opcionMenu = atoi(sNum);
		if (opcionMenu != 0)
		{
			switch (opcionMenu) {
			case 1: //Do something
				Plan.ingresarPlan();
				return 1;
				break;
			case 2: //Do something else
					//Blah blah blah
				return 2;
				break;
			case 3: //Do something else
				menuAhorro();
				//Blah blah blah
				return 3;
				break;
			default:
				cout << "Seleccione una opcion ente 1 y 3: ";
				cin >> new_opcionMenu;
				opcionMenu = new_opcionMenu;
				break;
			}
		}
		else
		{
			printf("La opcion selecionada no es un numero\n");
			menuPlanesDeAhorro();
		}
	} while (opcionMenu != 0);
}

int menuRegistrarAhorro()
{
	system("cls");
	ahorro Ahorro;
	int opcionMenu;
	int new_opcionMenu;
	char sNum[20];
	do {
		//Display menu
		cout << "/*************************Registrar ahorro**************************/" << endl;
		cout << "1) Editar" << endl;
		cout << "2) Eliminar" << endl;
		cout << "3) Volver a menu ahorro" << endl;
		cout << "Por favor selecione una opcion: ";
		cin >> sNum; //Get user input
		opcionMenu = atoi(sNum);
		if (opcionMenu != 0)
		{
			switch (opcionMenu) {
			case 1: //Do something
					//Blah blah blah
				return 1;
				break;
			case 2: //Do something else
					//Blah blah blah
				return 2;
				break;
			case 3: //Do something else
				menuAhorro();
				//Blah blah blah
				return 3;
				break;
			default:
				cout << "Seleccione una opcion ente 1 y 3: ";
				cin >> new_opcionMenu;
				opcionMenu = new_opcionMenu;
				break;
			}
		}
		else
		{
			printf("La opcion selecionada no es un numero\n");
			menuRegistrarAhorro();
		}
	} while (opcionMenu != 0);
}

int menuGeneracionDeEstadosDeCuenta()
{
	system("cls");
	int opcionMenu;
	int new_opcionMenu;
	char sNum[20];
	do {
		//Display menu
		cout << "/*************************Estados de cuenta**************************/" << endl;
		cout << "1) Lista o reporte por grupo" << endl;
		cout << "2) Lista o reporte por socio" << endl;
		cout << "3) Volver a menu ahorro" << endl;
		cout << "Por favor selecione una opcion: ";
		cin >> sNum; //Get user input
		opcionMenu = atoi(sNum);
		if (opcionMenu != 0)
		{
			switch (opcionMenu) {
			case 1: //Do something
					//Blah blah blah
				return 1;
				break;
			case 2: //Do something else
					//Blah blah blah
				return 2;
				break;
			case 3: //Do something else
				menuAhorro();
				//Blah blah blah
				return 3;
				break;
			default:
				cout << "Seleccione una opcion ente 1 y 3: ";
				cin >> new_opcionMenu;
				opcionMenu = new_opcionMenu;
				break;
			}
		}
		else
		{
			printf("La opcion selecionada no es un numero\n");
			menuGeneracionDeEstadosDeCuenta();
		}
	} while (opcionMenu != 0);
}

int menuCredito()
{
	system("cls");
	int opcionMenu;
	int new_opcionMenu;
	char sNum[20];
	do {
		//Display menu
		cout << "/*************************Credito**************************/" << endl;
		cout << "1) Registrar credito" << endl;
		cout << "2) Pago a credito" << endl;
		cout << "3) Estado de cuenta" << endl;
		cout << "4) Volver a menu principal" << endl;
		cout << "Por favor selecione una opcion: ";
		cin >> sNum; //Get user input
		opcionMenu = atoi(sNum);
		if (opcionMenu != 0)
		{
			switch (opcionMenu) {
			case 1: //Do something
					//Blah blah blah
				return 1;
				break;
			case 2: //Do something else
					//Blah blah blah
				return 2;
				break;
			case 3: //Do something else
				//Blah blah blah
				return 3;
				break;
			case 4: //Do something else
				menuPrincipal();
				//Blah blah blah
				return 3;
				break;
			default:
				cout << "Seleccione una opcion ente 1 y 3: ";
				cin >> new_opcionMenu;
				opcionMenu = new_opcionMenu;
				break;
			}
		}
		else
		{
			printf("La opcion selecionada no es un numero\n");
			menuGeneracionDeEstadosDeCuenta();
		}
	} while (opcionMenu != 0);
}

void socio::ingresarSocio() {

	system("cls");
	cout << "Ingrese nombre del socio:\n";
	cin >> Nombre;
	cout << "Ingrese primer apellido:\n";
	cin >> Apellido1;
	cout << "Ingrese segundo apellido:\n";
	cin >> Apellido2;
	cout << "Ingrese telefono casa:\n";
	cin >> TelefonoCasa;
	cout << "Ingrese relefono celular:";
	cin >> Celular;
	cout << "Ingrese correo electronico:";
	cin >> Email;
	cout << "Presione Enter para continuar";
	getchar();
	menuSocios();

}

void grupo::ingresarGrupo() {

	system("cls");
	cout << "Ingrese nombre del grupo:\n";
	cin >> NombreGrupo;
	getchar();
	menuGruposDeAhorro();

}

void plan::ingresarPlan() {

	system("cls");
	cout << "Ingrese nombre del plan:\n";
	cin >> NombrePlan;
	cout << "Ingrese descripcion del plan:\n";
	cin >> Descripcion;
	cout << "Ingrese plazo:\n";
	cin >> Plazo;
	cout << "Ingrese cuota:\n";
	cin >> Cuota;
	cout << "Ingrese fecha inicial del plan:\n";
	cin >> FechaInicial;
	cout << "Ingrese fecha final del plan:\n";
	cin >> FechaFinal;
	cout << "Ingrese periodicidad:\n";
	cin >> Periodicidad;
	getchar();
	menuPlanesDeAhorro();

}

void ahorro::ingresarAhorro() {

	system("cls");
	cout << "Ingrese cuota:\n";
	cin >> Cuota;
	cout << "Ingrese estado:\n";
	cin >> Estado;
	getchar();
	menuPlanesDeAhorro();

}

void getConnected()
{
	SqlConnection^ cn = gcnew SqlConnection();
	SqlCommand^ cmd;
	SqlDataAdapter^ da;
	DataTable^ dt;

	//cn->ConnectionString = "SERVER=DEVSQL, 1433;DATABASE=Production;Integrated Security=SSPI;";
	cn->ConnectionString = "SERVER=(local);DATABASE=Banco;Integrated Security=SSPI;";
	cn->Open();
	//Server = HEADSHOT - PC\SQLEXPRESS; Databases = ManageStaff; User ID = sa; Pwd = 123456
	//cmd = gcnew SqlCommand("SELECT top 20 ProcessOrderCriticalOperationId, ProcessOrderId, CriticalOperationId FROM CriticalQualityActions.ProcessOrderCriticalOperation", cn);
	cmd = gcnew SqlCommand("SELECT * FROM [dbo].[Socio]", cn);
	cmd->CommandText;

	cout << "Message: Conexion exitosa git5"  << endl;

	da = gcnew SqlDataAdapter(cmd);
	dt = gcnew DataTable("TableStaffTemp");

	da->Fill(dt);

	//for (int i = 0; i < dt->Rows->Count - 1; i++)
	//{
	//	String^ value_string;
	//	/*value_string = dt->Rows->ToString();*/
	//	value_string = dt->[i]->ToString();
	//	Console::WriteLine(value_string);
	//	//std::cout << prd(value_string, 1, 10) << " | "
	//	//	<< prd(value_string, 2, 10) << " | "
	//	//	<< prd(value_string , 4, 10) << "\n";
	//}

	cn->Close();
	Console::ReadLine();
}
