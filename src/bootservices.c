#include "bootservices.h"
#include "limine_requests.h"

#define CALL_SERVICE(x) (x.response)

#define DEFAULT_TERMINAL_WRITER 0x0
uint64_t terminal_writer = DEFAULT_TERMINAL_WRITER; //Variable global no es muy deluxe en el kernel tener variables globales

void service_error() { //bucle infinito cuando hay error de servicio por si nos calentamos
    while (1) {
        __asm__("hlt");
    }
}

char * get_bootloader_name() { 
    return CALL_SERVICE(BOOTLOADER)->name;  //llamamos a bootlader(info request,definido en limine requests ) y nos devuelve el campo name.
}

char * get_bootloader_version() {
    return CALL_SERVICE(BOOTLOADER)->version;
}
uint64_t get_terminal_count() {
    return CALL_SERVICE(TERMINAL)->terminal_count;
}

uint64_t get_current_terminal() {
    return terminal_writer;
}

void set_terminal_writer(uint64_t terminal) {
    if (terminal > get_terminal_count()) {
        service_error();
    }
    terminal_writer = terminal;
}

void generic_terminal_writer(const char* str, uint64_t length) {
    struct limine_terminal * terminal = CALL_SERVICE(TERMINAL)->terminals[terminal_writer];
    CALL_SERVICE(TERMINAL)->write(terminal, str, length);
}

void (*get_terminal_writer())(const char*, uint64_t) {
    return generic_terminal_writer;
}


uint64_t get_memory_map_entries() {
    return CALL_SERVICE(MEMMAP)->entry_count;
}

uint64_t get_memory_map_base(uint64_t entry) {
    return CALL_SERVICE(MEMMAP)->entries[entry]->base;
}

uint64_t get_memory_map_length(uint64_t entry) {
    return CALL_SERVICE(MEMMAP)->entries[entry]->length;
}

uint64_t get_memory_map_type(uint64_t entry) {
    return CALL_SERVICE(MEMMAP)->entries[entry]->type;
}

uint64_t get_kernel_address_physical() {
    return CALL_SERVICE(KERNEL)->physical_base;
}

uint64_t get_rsdp_address() {
    return (uint64_t)CALL_SERVICE(RSDP)->address;
}

uint64_t get_kernel_address_virtual() {
    return CALL_SERVICE(KERNEL)->virtual_base;
}