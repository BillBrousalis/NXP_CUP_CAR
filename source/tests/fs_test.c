//-------------------------------------------------------------------------------------------------------------
//	fsystem.c
//-------------------------------------------------------------------------------------------------------------
#include		"includes.h"

//-------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------
#define         TEST_BLOCK_SIZE         512
#define         TEST_BLOCKS_NUM         2048
//==============================================================================
char buff[TEST_BLOCK_SIZE];
char buff2[TEST_BLOCK_SIZE];

FRESULT scan_files(char* path);

//==============================================================================
//
//==============================================================================
void fs_test(void)
{
  FRESULT fr;     /* FatFs return code */
  uint32_t i;
  uint32_t bw;
  DWORD ThrSpeed;
  static float SpdKBPS;
  DWORD fre_clust, fre_sect, tot_sect;

  printf("********* FatFs Media Test ***********\n");

  f_unlink ("wrtest.txt");								/* Delete an existing file or directory */

//--------------------------------------------------------------------
    /* Get volume information and free clusters of drive 1 */
  printf("===== Volume Info ====== \n");
  fr = f_getfree("", &fre_clust, &fs);
  if (fr)
  {
    printf("Unable to get Media info \n");
    return;
  }

    /* Get total sectors and free sectors */
  tot_sect = (fs->n_fatent - 2) * fs->csize;
  fre_sect = fre_clust * fs->csize;

    /* Print the free space (assuming 512 bytes/sector) */
  printf("%10lu KiB total drive space.\n%10lu KiB available.\n", tot_sect / 2, fre_sect / 2);
//--------------------------------------------------------------------
  printf("===== File R/W througput test ===== \n");
  fr = f_open(&fil, "wrtest.txt", FA_WRITE | FA_CREATE_NEW | FA_CREATE_ALWAYS);
  if (fr)
  {
    printf("File Error\n");
    return; // (int)fr;
  }

  mysrand(0xaa);
  for(i=0;i<TEST_BLOCK_SIZE;i++)buff[i] = (char)myrand(0xff);
  memcpy(buff2,buff,TEST_BLOCK_SIZE);


  ThrSpeed = GetSystemTimer();
  for(i=0;i<TEST_BLOCKS_NUM;i++)
  {
    f_write (&fil, (const void*)buff, TEST_BLOCK_SIZE, (UINT *)&bw);	/* Write data to a file */
  }
  f_close (&fil);
  ThrSpeed = GetSystemTimer() - ThrSpeed;
  SpdKBPS =  (1048576.0f / (float) ThrSpeed);
  printf("Write speed = %0.1fKBPS\r\n",SpdKBPS);

  fr = f_open(&fil, "wrtest.txt", FA_READ );
  if (fr)
  {
    printf("File Error      \n");
    return; // (int)fr;
  }

  ThrSpeed = GetSystemTimer();
  for(i=0;i<TEST_BLOCKS_NUM;i++)
  {
    f_read (&fil, (char *)buff, TEST_BLOCK_SIZE, (UINT *)&bw);
  }
  ThrSpeed = GetSystemTimer() - ThrSpeed;
  SpdKBPS =  ((TEST_BLOCKS_NUM * TEST_BLOCK_SIZE) / (float) ThrSpeed);
  printf("Read speed = %0.1fKBPS\r\n",SpdKBPS);

  printf("===== File verification ===== \n");
  uint32_t flg = 0;
  for(i=0;i<TEST_BLOCKS_NUM;i++)
  {
    printf("=");
    f_read (&fil, (char *)buff, TEST_BLOCK_SIZE, (UINT *)&bw);
    if(memcmp(buff2,buff,TEST_BLOCK_SIZE) !=0)
    {
      printf("\nFile read error at block %d\r\n",(int)i);
      flg = 1;
    }
  }
  f_close (&fil);
  printf("\n");
  if(flg == 0)
  {
    printf("File verified OK ! \r\n");
  }
  else
    printf("File verification error ! \r\n");
  printf("===== Directory structure ===== \n");
  buff[0] = 0; buff[1] = 0;
  scan_files(buff);

}
//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
FRESULT scan_files(char* path)        						/* Start node to be scanned (***also used as work area***) */

{
    FRESULT res;
    DIR dir;
    UINT i;
    static FILINFO fno;


    res = f_opendir(&dir, path);                       		/* Open the directory */
    if (res == FR_OK) {
        for (;;) {
            res = f_readdir(&dir, &fno);                   	/* Read a directory item */
            if (res != FR_OK || fno.fname[0] == 0) break;  	/* Break on error or end of dir */
            if (fno.fattrib & AM_DIR) {                    	/* It is a directory */
                i = strlen(path);
                sprintf(&path[i], "/%s", fno.fname);
                res = scan_files(path);                    	/* Enter the directory */
                if (res != FR_OK) break;
                path[i] = 0;
            } else {                                       	/* It is a file. */
                printf("%s/%s\n", path, fno.fname);
            }
        }
        f_closedir(&dir);
    }

    return res;
}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
