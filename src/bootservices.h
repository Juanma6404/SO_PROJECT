#ifndef _BOOTSERVICES_H
#define _BOOTSERVICES_H
#include "limine.h"
#include <stdint.h>

char * get_bootloader_name(); 
char * get_bootloader_version();
//Funciones para coger el nombre y la version del bootloader

uint64_t get_terminal_count(); //Numero de terminales
uint64_t get_current_terminal();

uint64_t get_memory_map_entries();
uint64_t get_memory_map_base(uint64_t entry);
uint64_t get_memory_map_length(uint64_t entry);
uint64_t get_memory_map_type(uint64_t entry);

uint64_t get_kernel_address_physical();
uint64_t get_kernel_address_virtual();

uint64_t get_rsdp_address();

void set_terminal_writer(uint64_t terminal);//Terminales que queremos utilizar
void (*get_terminal_writer())(const char*, uint64_t);//puntero a una funcion
#endif