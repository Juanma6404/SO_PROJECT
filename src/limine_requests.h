#ifndef _LIMINE_REQUEST_H
#define _LIMINE_REQUEST_H

#define BOOTLOADER  bootloader_info_request
#define TERMINAL    terminal_request
#define MEMMAP      memmap_request
#define KERNEL      kernel_address_request
#define RSDP        rsdp_request
#define SMBIOS      smbios_request

static volatile struct limine_terminal_request terminal_request = { //Peticion a la terminal inicial
    .id = LIMINE_TERMINAL_REQUEST,
    .revision = 0
};
//Lo de static es que la siguiente vez que se invoque coge el valor guardado y volatile que se pueda modificar en cualquier momento como por una interrupcion
static volatile struct limine_bootloader_info_request bootloader_info_request = { 
    .id = LIMINE_BOOTLOADER_INFO_REQUEST,
    .revision = 0
};

static volatile struct limine_memmap_request memmap_request = { 
    .id = LIMINE_MEMMAP_REQUEST,
    .revision = 0
};

static volatile struct limine_kernel_address_request kernel_address_request = {
    .id = LIMINE_KERNEL_ADDRESS_REQUEST,
    .revision = 0
};

static volatile struct limine_rsdp_request rsdp_request = { //Descriptor raiz para los dispositivos
    .id = LIMINE_RSDP_REQUEST,
    .revision = 0
};

static volatile struct limine_smbios_request smbios_request = {
    .id = LIMINE_SMBIOS_REQUEST,
    .revision = 0
};

#endif