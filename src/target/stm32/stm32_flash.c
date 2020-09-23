#include "target.h"
#include "stm32_flash.h"


void target_family_populate_info(){
  //interrogate the device to see which in the family it is
  target_startup.info.device_id = 0;
  target_startup.info.flash_page_table[0] = 128;
  target_startup.info.ram_work_address = 0x10000000;
  target_startup.info.ram_work_size = 0x8000;

}

uint32_t target_family_erase_sector(uint32_t bank, uint32_t sector){
  uint32_t range = FLASH_VOLTAGE_RANGE_1;
  if( target_startup.external.voltage_millivolts < 3000 ){
    range = FLASH_VOLTAGE_RANGE_2;
  }
  FLASH_Erase_Sector(sector, bank, range);
}

uint32_t target_family_copy_ram_to_flash(uint32_t source_address, uint32_t flash_address, uint32_t nbyte){

  //use info->voltage_millivolts to determine write width

  uint32_t type_program = FLASH_TYPEPROGRAM_FLASHWORD;

  for(uint32_t bytes_written = 0; bytes_written < nbyte; bytes_written++){

    if( nbyte - bytes_written < 4 ){
      //program fewer than 4 bytes
    }

    HAL_FLASH_Program(
      FLASH_TYPEPROGRAM_FLASHWORD, 
      flash_address + bytes_written, 
      source_address+bytes_written);
    }

  return 0;
}
