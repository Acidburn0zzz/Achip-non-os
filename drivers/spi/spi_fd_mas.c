#include <types.h>
#include "common_all.h"
#include "cache.h"
#include "sp_interrupt.h"




typedef struct regs_spi_t_ {
	// Group 091 : SPI_MASTER

    unsigned int  MST_TX_DATA_ADDR                      ; // 00  (ADDR : 0x9C00_2D80)
    unsigned int  MST_TX_DATA_3_2_1_0                   ; // 01  (ADDR : 0x9C00_2D84)
    unsigned int  MST_TX_DATA_7_6_5_4                   ; // 02  (ADDR : 0x9C00_2D88)
    unsigned int  MST_TX_DATA_11_10_9_8                 ; // 03  (ADDR : 0x9C00_2D8C)
    unsigned int  MST_TX_DATA_15_14_13_12               ; // 04  (ADDR : 0x9C00_2D90)
    unsigned int  G091_RESERVED_0[4]                    ; //     (ADDR : 0x9C00_2D94) ~ (ADDR : 0x9C00_2DA0)
    unsigned int  MST_RX_DATA_3_2_1_0                   ; // 09  (ADDR : 0x9C00_2DA4)
    unsigned int  MST_RX_DATA_7_6_5_4                   ; // 10  (ADDR : 0x9C00_2DA8)
    unsigned int  MST_RX_DATA_11_10_9_8                 ; // 11  (ADDR : 0x9C00_2DAC)
    unsigned int  MST_RX_DATA_15_14_13_12               ; // 12  (ADDR : 0x9C00_2DB0)
	unsigned int  FIFO_DATA                             ; // 13  (ADDR : 0x9C00_2DB4)
  	unsigned int  SPI_STATUS                            ; // 14  (ADDR : 0x9C00_2DB8)
  	unsigned int  SPI_CONFIG                            ; // 15  (ADDR : 0x9C00_2DBC)
	unsigned int  G091_RESERVED_1                       ; // 16  (ADDR : 0x9C00_2DC0)
    unsigned int  SPI_CTRL_CLKSEL                       ; // 17  (ADDR : 0x9C00_2DC4)
    unsigned int  BYTE_NO                               ; // 18  (ADDR : 0x9C00_2DC8)
    unsigned int  SPI_INT_BUSY                          ; // 19  (ADDR : 0x9C00_2DCC)
    unsigned int  DMA_CTRL                              ; // 20  (ADDR : 0x9C00_2DD0)
    unsigned int  DMA_LENGTH                            ; // 21  (ADDR : 0x9C00_2DD4)
    unsigned int  DMA_ADDR                              ; // 22  (ADDR : 0x9C00_2DD8)
    unsigned int  G091_RESERVED_2[1]                    ; // 23  (ADDR : 0x9C00_2DDC)
    unsigned int  DMA_ADDR_STAT                         ; // 24  (ADDR : 0x9C00_2DE0)
    unsigned int  G091_RESERVED_3[1]                    ; // 25  (ADDR : 0x9C00_2DE4)
    unsigned int  UART_DMA_CTRL                         ; // 26  (ADDR : 0x9C00_2DE8)
    unsigned int  G091_RESERVED_4[1]                    ; // 27  (ADDR : 0x9C00_2DEC)
    unsigned int  SPI_MST_DEBUG_SEL                     ; // 28  (ADDR : 0x9C00_2DF0) 
    unsigned int  SPI_COM_DEBUG_SEL                     ; // 29  (ADDR : 0x9C00_2DF4)
    unsigned int  SPI_EXTRA_CYCLE                       ; // 30  (ADDR : 0x9C00_2DF8)
    unsigned int  MST_DMA_DATA_RDY                      ; // 31  (ADDR : 0x9C00_2DFC)
}SPI_MAS_REG;


/* SPI MST DMA_SIZE */
#define MST_DMA_RSIZE(x)       (x<<16)
#define MST_DMA_WSIZE(x)       (x<<0)

/* SPI MST DMA config */
#define MST_DMA_EN             (1<<1)
#define MST_DMA_START          (1<<0)


/* SPI MST STATUS */
#define TOTAL_LENGTH(x)        (x<<24)
#define TX_LENGTH(x)           (x<<16)
#define RX_CNT                 (0x0F<<12)
#define TX_CNT                 (0x0F<<12)
#define SPI_BUSY               (1<<7)
#define FINISH_FLAG            (1<<6)
#define RX_FULL_FLAG           (1<<5)
#define RX_EMP_FLAG            (1<<4)
#define TX_FULL_FLAG           (1<<3)
#define TX_EMP_FLAG            (1<<2)
#define SPI_SW_RST             (1<<1)
#define SPI_START_FD           (1<<0)

#define CLEAN_FLUG_MASK (~0xF800)


/* SPI MST CONFIG */
#define CLK_DIVIDER(x)         (x<<16)
#define FINISH_FLAG_MASK       (1<<15)
#define RX_FULL_FLAG_MASK      (1<<14)
#define RX_EMP_FLAG_MASK       (1<<13)
#define TX_FULL_FLAG_MASK      (1<<12)
#define TX_EMP_FLAG_MASK       (1<<11)
#define WRITE_BYTE(x)          (x<<9)
#define READ_BYTE(x)           (x<<7)
#define FD_SEL                 (1<<6)
#define CS_SEL                 (1<<5)
#define LSB_SEL                (1<<4)
#define DELAY_ENABLE           (1<<3)
#define CPHA_W                 (1<<2)
#define CPHA_R                 (1<<1)
#define CPOL                   (1<<0)


#define CLEAN_RW_BYTE          (~0x780)
#define CLEAN_SPI_MODE         (~0x7)


#define SPI_FD_INTR            (1<<7)

#define SPI_MASTER_NUM         (4)
#define SPI_MSG_DATA_SIZE      (255)


#define SPI_CLK_RATE           202500000
#define SPI_INIT_FREQ          5000000
#define SPI_MAX_FREQ           25000000

#define SPI_INIT_MODE          3



#define SPI_REG_ADDR_0         0x9C002D80
#define SPI_REG_ADDR_1         0x9C00F480
#define SPI_REG_ADDR_2         0x9C00F600
#define SPI_REG_ADDR_3         0x9C00F780


static volatile UINT32* grp2_sft_cfg = (UINT32 *) 0x9c000100;
static volatile UINT32* grp3_sft_cfg = (UINT32 *) 0x9c000180;


static volatile unsigned int spi_repeat_cnt = 0;


#define SPI0_DMA_INT   (144)
#define SPI0_RISC_INT  (146)

#define SPI1_DMA_INT   (67)
#define SPI1_RISC_INT  (69)

#define SPI2_DMA_INT   (70)
#define SPI2_RISC_INT  (72)

#define SPI3_DMA_INT   (73)
#define SPI3_RISC_INT  (75)


enum 
{
	SPI_MASTER_0 = 0,
	SPI_MASTER_1 = 1,
	SPI_MASTER_2 = 2,
	SPI_MASTER_3 = 3,
};



struct spi_master_ctlr {

    unsigned int spi_ip;
	unsigned int freq;		
	unsigned int reg_adr;
	unsigned int mode;	

    unsigned int rx_cur_len;
    unsigned int tx_cur_len;

	u8 tx_data_buf[SPI_MSG_DATA_SIZE];
	u8 rx_data_buf[SPI_MSG_DATA_SIZE];
	
	u8 *buf;
    unsigned int len;
    unsigned int txlen;	
	
};

struct spi_master_ctlr spi_mas_ctlr[SPI_MASTER_NUM];



void sp_spi_master_set_freq_mode(unsigned int spi_no, unsigned int freq, unsigned int mode)
{
     if(spi_no <= SPI_MASTER_NUM){
	 	if(freq > SPI_MAX_FREQ)
		    spi_mas_ctlr[spi_no].freq = SPI_MAX_FREQ;	
	 	else
	 	    spi_mas_ctlr[spi_no].freq = freq;

		if(mode > 4)
		    spi_mas_ctlr[spi_no].mode = SPI_INIT_MODE;	
	 	else
	 	    spi_mas_ctlr[spi_no].mode = mode;
     }

}


void sp_spi_master_fd_init()
{
	unsigned int i;
	unsigned int div;
	unsigned int temp_reg;	

    SPI_MAS_REG * regs0;	

	//printf("spi_master_init\n");
	
	grp2_sft_cfg[22] = (0x7F7F0000 |(5 << 8) |(4 << 0));
	grp2_sft_cfg[23] = (0x7F7F0000 |(6 << 8) |(7 << 0));	
	grp2_sft_cfg[24] = (0x7F7F0000 |(8 << 0));		
	
	//printf("grp2_sft_cfg[22] %x, grp2_sft_cfg %x\n", grp2_sft_cfg[22], grp2_sft_cfg);


     for(i=0;i<SPI_MASTER_NUM;i++){
	 	spi_mas_ctlr[i].spi_ip = i;
	 	spi_mas_ctlr[i].freq = SPI_INIT_FREQ;		

		switch(i){
			case 0:
		        spi_mas_ctlr[0].reg_adr = SPI_REG_ADDR_0;
		        break;
			case 1:
		        spi_mas_ctlr[1].reg_adr = SPI_REG_ADDR_1;
		        break;
			case 2:
		        spi_mas_ctlr[2].reg_adr = SPI_REG_ADDR_2;
		        break;
			case 3:
		        spi_mas_ctlr[3].reg_adr = SPI_REG_ADDR_3;
		        break;
			default:
				break;
		}

		spi_mas_ctlr[i].mode = SPI_INIT_MODE;
	
		regs0 = (SPI_MAS_REG *)spi_mas_ctlr[i].reg_adr;
		div = SPI_CLK_RATE / SPI_INIT_FREQ ;
		div = (div / 2) - 1;

		temp_reg = FD_SEL | ((div & 0xffff) << 16);  
		temp_reg &= CLEAN_RW_BYTE;
		temp_reg |= WRITE_BYTE(0) | READ_BYTE(0);
		temp_reg &= CLEAN_FLUG_MASK;
		regs0->SPI_CONFIG = temp_reg;	
		
     }

}



void  spi_irq_handler(unsigned int spi_no)
{
	SPI_MAS_REG * regs0 = (SPI_MAS_REG *)spi_mas_ctlr[spi_no].reg_adr;
	unsigned int i;


	//printf("spi_irq_rw \n"); 


		if((spi_mas_ctlr[spi_no].tx_cur_len < spi_mas_ctlr[spi_no].txlen) || ((regs0->SPI_STATUS & TX_EMP_FLAG) == TX_EMP_FLAG)){
			if((regs0->SPI_STATUS & RX_FULL_FLAG)==RX_FULL_FLAG){
				for(i=0;i<16;i++){	 // if READ_BYTE(0) i<16  can set the condition at here
				    spi_mas_ctlr[spi_no].rx_data_buf[spi_mas_ctlr[spi_no].rx_cur_len] = regs0->FIFO_DATA;
					//printf("RXcnt203 data 0x%x	rx_cur_len = %d \n",spi_mas_ctlr[spi_no].rx_data_buf[spi_mas_ctlr[spi_no].rx_cur_len],spi_mas_ctlr[spi_no].rx_cur_len);		   
				    spi_mas_ctlr[spi_no].rx_cur_len++;
				}
			}
			while((regs0->SPI_STATUS & RX_CNT )){	
				spi_mas_ctlr[spi_no].rx_data_buf[spi_mas_ctlr[spi_no].rx_cur_len] = regs0->FIFO_DATA;
				//printf("RXcnt221 data 0x%x  rx_cur_len = %d \n",spi_mas_ctlr[spi_no].rx_data_buf[spi_mas_ctlr[spi_no].rx_cur_len],spi_mas_ctlr[spi_no].rx_cur_len);
				spi_mas_ctlr[spi_no].rx_cur_len++;
				if((spi_mas_ctlr[spi_no].tx_cur_len < spi_mas_ctlr[spi_no].txlen) && ((regs0->SPI_STATUS & TX_FULL_FLAG) != TX_FULL_FLAG)){
				     regs0->FIFO_DATA = spi_mas_ctlr[spi_no].tx_data_buf[spi_mas_ctlr[spi_no].tx_cur_len];
					 spi_mas_ctlr[spi_no].tx_cur_len++;		   
				}   
		    }
			while(spi_mas_ctlr[spi_no].txlen-spi_mas_ctlr[spi_no].tx_cur_len){
			    //printf("tx_data_buf554 0x%x  ,tx_cur_len %d \n",spi_mas_ctlr[spi_no].tx_data_buf[spi_mas_ctlr[spi_no].tx_cur_len],spi_mas_ctlr[spi_no].tx_cur_len);
			    if((regs0->SPI_STATUS & TX_FULL_FLAG)==TX_FULL_FLAG){
			        break;
			    	}
			        regs0->FIFO_DATA = spi_mas_ctlr[spi_no].tx_data_buf[spi_mas_ctlr[spi_no].tx_cur_len];
					spi_mas_ctlr[spi_no].tx_cur_len++;
			}  
       }else if((regs0->SPI_STATUS & RX_FULL_FLAG)==RX_FULL_FLAG){
	       for(i=0;i<16;i++){	 // if READ_BYTE(0) i<16  can set the condition at here
		       spi_mas_ctlr[spi_no].rx_data_buf[spi_mas_ctlr[spi_no].rx_cur_len] = regs0->FIFO_DATA;
			   //printf("RXcnt203 data 0x%x	rx_cur_len = %d \n",spi_mas_ctlr[spi_no].rx_data_buf[spi_mas_ctlr[spi_no].rx_cur_len],spi_mas_ctlr[spi_no].rx_cur_len);		   
			   spi_mas_ctlr[spi_no].rx_cur_len++;
		    }
	   }else {
	       while((regs0->SPI_STATUS & RX_CNT )){	
		       spi_mas_ctlr[spi_no].rx_data_buf[spi_mas_ctlr[spi_no].rx_cur_len] = regs0->FIFO_DATA;
			   //printf("RXcnt210 data 0x%x	rx_cur_len = %d \n",spi_mas_ctlr[spi_no].rx_data_buf[spi_mas_ctlr[spi_no].rx_cur_len],spi_mas_ctlr[spi_no].rx_cur_len);
			    spi_mas_ctlr[spi_no].rx_cur_len++;
		   }
	   }


	if((regs0->SPI_STATUS & FINISH_FLAG)==FINISH_FLAG){

   	    if((regs0->SPI_STATUS & RX_FULL_FLAG)==RX_FULL_FLAG){
		    for(i=0;i<16;i++){	 // if READ_BYTE(0) i<16  can set the condition at here
			   spi_mas_ctlr[spi_no].rx_data_buf[spi_mas_ctlr[spi_no].rx_cur_len] = regs0->FIFO_DATA;
			   //printf("RXcnt203 data 0x%x	rx_cur_len = %d \n",spi_mas_ctlr[spi_no].rx_data_buf[spi_mas_ctlr[spi_no].rx_cur_len],spi_mas_ctlr[spi_no].rx_cur_len);		   
			    spi_mas_ctlr[spi_no].rx_cur_len++;
		    }
	    }

	    while((regs0->SPI_STATUS & RX_CNT )){	
		    spi_mas_ctlr[spi_no].rx_data_buf[spi_mas_ctlr[spi_no].rx_cur_len] = regs0->FIFO_DATA;
		    //printf("RXcnt569 data 0x%x  rx_cur_len = %d \n",spi_mas_ctlr[spi_no].rx_data_buf[spi_mas_ctlr[spi_no].rx_cur_len],spi_mas_ctlr[spi_no].rx_cur_len);
		    spi_mas_ctlr[spi_no].rx_cur_len++;
	    }
		//printf("finish\n");

		if((spi_mas_ctlr[spi_no].txlen >0) && (spi_mas_ctlr[spi_no].rx_cur_len >= spi_mas_ctlr[spi_no].txlen))
		memcpy(spi_mas_ctlr[spi_no].buf, &spi_mas_ctlr[spi_no].rx_data_buf[spi_mas_ctlr[spi_no].txlen], (spi_mas_ctlr[spi_no].rx_cur_len-spi_mas_ctlr[spi_no].txlen));
		else
		memcpy(spi_mas_ctlr[spi_no].buf, &spi_mas_ctlr[spi_no].rx_data_buf[0], spi_mas_ctlr[spi_no].rx_cur_len);
		
		regs0->SPI_CONFIG &= CLEAN_FLUG_MASK;
		regs0->SPI_STATUS |= SPI_SW_RST;
		
	}


	regs0->SPI_CONFIG &= CLEAN_FLUG_MASK;
	regs0->SPI_CONFIG |= FINISH_FLAG_MASK | TX_EMP_FLAG_MASK | RX_FULL_FLAG_MASK;		   // bits_per_word = 8 , data_unit = 1byte


}




static void spi0_isr_cfg()
{
	//printf("[CFG] spi0\n");
	hal_interrupt_configure(SPI0_RISC_INT, 0, 1);
	hal_interrupt_unmask(SPI0_RISC_INT);
}


void spi0_callback(void)
{
	//printf("@Spi0_Hello[%d]\n", ++spi_repeat_cnt);
	spi_irq_handler(0);
}


static void spi1_isr_cfg()
{
	//printf("[CFG] spi1\n");
	hal_interrupt_configure(SPI1_RISC_INT, 0, 1);
	hal_interrupt_unmask(SPI1_RISC_INT);

}


void spi1_callback(void)
{
	//printf("@Spi1_Hello[%d]\n", ++spi_repeat_cnt);
	spi_irq_handler(1);

}

static void spi2_isr_cfg()
{
	//printf("[CFG] spi1\n");
	hal_interrupt_configure(SPI2_RISC_INT, 0, 1);
	hal_interrupt_unmask(SPI2_RISC_INT);	
}


void spi2_callback(void)
{
	//printf("@Spi2_Hello[%d]\n", ++spi_repeat_cnt);
	spi_irq_handler(2);
}

static void spi3_isr_cfg()
{
	//printf("[CFG] spi1\n");
	hal_interrupt_configure(SPI3_RISC_INT, 0, 1);
	hal_interrupt_unmask(SPI3_RISC_INT);		
}


void spi3_callback(void)
{
	//printf("@Spi2_Hello[%d]\n", ++spi_repeat_cnt);
	spi_irq_handler(3);	
}


void spi_irq_init(unsigned int spi_no)
{
	static interrupt_operation spi_opt;	

	switch(spi_no){
		case 0:
		    memcpy(spi_opt.dev_name, "Spi0", strlen("Spi0"));
		    spi_opt.vector = SPI0_RISC_INT;
		    spi_opt.device_config = spi0_isr_cfg;
		    spi_opt.interrupt_handler = spi0_callback;
		    interrupt_register(&spi_opt);
			break;
		case 1:
			memcpy(spi_opt.dev_name, "Spi1", strlen("Spi1"));
			spi_opt.vector = SPI1_RISC_INT;
			spi_opt.device_config = spi1_isr_cfg;
			spi_opt.interrupt_handler = spi1_callback;
			interrupt_register(&spi_opt);
			break;
		case 2:
			memcpy(spi_opt.dev_name, "Spi2", strlen("Spi2"));
			spi_opt.vector = SPI2_RISC_INT;
			spi_opt.device_config = spi2_isr_cfg;
			spi_opt.interrupt_handler = spi2_callback;
			interrupt_register(&spi_opt);
			break;
		case 3:
			memcpy(spi_opt.dev_name, "Spi3", strlen("Spi3"));
			spi_opt.vector = SPI3_RISC_INT;
			spi_opt.device_config = spi3_isr_cfg;
			spi_opt.interrupt_handler = spi3_callback;
			interrupt_register(&spi_opt);
			break;

		default:
			break;
	}


}



void sp_spi_master_fd_read(unsigned int spi_no, u8  *data_buf , unsigned int len)
{

	unsigned int temp_reg;
	unsigned int div;
	unsigned int i;	
	SPI_MAS_REG * regs0 = (SPI_MAS_REG *)spi_mas_ctlr[spi_no].reg_adr;

	spi_mas_ctlr[spi_no].rx_cur_len = 0 ;
	spi_mas_ctlr[spi_no].tx_cur_len = 0 ;

	//set clock
	div = SPI_CLK_RATE / spi_mas_ctlr[spi_no].freq ;
	div = (div / 2) - 1;

	temp_reg = FD_SEL | ((div & 0xffff) << 16);                     //set up full duplex frequency and enable  full duplex 
	temp_reg &= CLEAN_RW_BYTE;
	temp_reg |= WRITE_BYTE(0) | READ_BYTE(0) | RX_FULL_FLAG_MASK | FINISH_FLAG_MASK;          // bits_per_word = 8 , data_unit = 1byte
	//temp_reg |= DELAY_ENABLE;

	temp_reg &= CLEAN_SPI_MODE;
	
	switch(spi_mas_ctlr[spi_no].mode){
		case 1:
			temp_reg |= CPHA_W | CPHA_R;
			break;
		case 2:
			temp_reg |= CPOL;  
			break;
		case 3:
			temp_reg |= CPHA_W | CPHA_R;
			temp_reg |= CPOL;  
			break;

		default:
			break;
	}

	regs0->SPI_CONFIG = temp_reg;

	//printf("SPI_CONFIG 0x%x \n",regs0->SPI_CONFIG);    


    regs0->FIFO_DATA = 0x00; // keep tx not empty in only read mode
	
	regs0->SPI_STATUS = TOTAL_LENGTH(len) | TX_LENGTH(0);
	regs0->SPI_STATUS |= SPI_START_FD;

	
	while((regs0->SPI_STATUS & SPI_BUSY) == SPI_BUSY){
	    if((regs0->SPI_STATUS & RX_FULL_FLAG)==RX_FULL_FLAG){
		    for(i=0;i<8;i++){	 // if READ_BYTE(0) i<16  can set the condition at here
		 	    spi_mas_ctlr[spi_no].rx_data_buf[spi_mas_ctlr[spi_no].rx_cur_len] = regs0->FIFO_DATA;
		 	    printf("RXcnt203 data 0x%x  rx_cur_len = %d \n",spi_mas_ctlr[spi_no].rx_data_buf[spi_mas_ctlr[spi_no].rx_cur_len],spi_mas_ctlr[spi_no].rx_cur_len);		   
		 	    spi_mas_ctlr[spi_no].rx_cur_len++;
		 	}
		}
	
		while((regs0->SPI_STATUS & RX_CNT )){	
		    spi_mas_ctlr[spi_no].rx_data_buf[spi_mas_ctlr[spi_no].rx_cur_len] = regs0->FIFO_DATA;
		    //printf("RXcnt210 data 0x%x  rx_cur_len = %d \n",spi_mas_ctlr[spi_no].rx_data_buf[spi_mas_ctlr[spi_no].rx_cur_len],spi_mas_ctlr[spi_no].rx_cur_len);
			spi_mas_ctlr[spi_no].rx_cur_len++;
		}

	};


	if((regs0->SPI_STATUS & FINISH_FLAG)==FINISH_FLAG){

   	    if((regs0->SPI_STATUS & RX_FULL_FLAG)==RX_FULL_FLAG){
		    for(i=0;i<8;i++){	 // if READ_BYTE(0) i<16  can set the condition at here
			   spi_mas_ctlr[spi_no].rx_data_buf[spi_mas_ctlr[spi_no].rx_cur_len] = regs0->FIFO_DATA;
			   //printf("RXcnt203 data 0x%x	rx_cur_len = %d \n",spi_mas_ctlr[spi_no].rx_data_buf[spi_mas_ctlr[spi_no].rx_cur_len],spi_mas_ctlr[spi_no].rx_cur_len);		   
			    spi_mas_ctlr[spi_no].rx_cur_len++;
		    }
	    }

	    while((regs0->SPI_STATUS & RX_CNT )){	
		    spi_mas_ctlr[spi_no].rx_data_buf[spi_mas_ctlr[spi_no].rx_cur_len] = regs0->FIFO_DATA;
		    //printf("RXcnt221 data 0x%x  rx_cur_len = %d \n",spi_mas_ctlr[spi_no].rx_data_buf[spi_mas_ctlr[spi_no].rx_cur_len],spi_mas_ctlr[spi_no].rx_cur_len);
		    spi_mas_ctlr[spi_no].rx_cur_len++;
	    }
		
	memcpy(data_buf, &spi_mas_ctlr[spi_no].rx_data_buf[0], spi_mas_ctlr[spi_no].rx_cur_len);

	regs0->SPI_CONFIG &= CLEAN_FLUG_MASK;
	regs0->SPI_STATUS |= SPI_SW_RST;
 
	}
		

 
	//printf("finish FD read\n");


}

void sp_spi_master_fd_write(unsigned int spi_no,u8  *buf, unsigned int len)
{
	unsigned int temp_reg;
	unsigned int div;
	unsigned int i;
	
	SPI_MAS_REG * regs0 = (SPI_MAS_REG *)spi_mas_ctlr[spi_no].reg_adr;

	spi_mas_ctlr[spi_no].rx_cur_len = 0 ;
	spi_mas_ctlr[spi_no].tx_cur_len = 0 ;


	memcpy(&spi_mas_ctlr[spi_no].tx_data_buf[0], buf, len);


	//printf("tx_data_buf[0] = 0x%x, tx_data_buf[1] = 0x%x\n", spi_mas_ctlr[spi_no].tx_data_buf[0], spi_mas_ctlr[spi_no].tx_data_buf[1]);	
	//printf("data_bufW00_addr:%x\n ",buf);
	//printf("spi_regs 0x%x \n",regs0);
	
	//printf("FIFO_DATA_addr 0x%x \n",&regs0->FIFO_DATA);
	//printf("SPI_CONFIG_addr 0x%x \n",&regs0->SPI_CONFIG);
	//printf("SPI_CONFIG 0x%x \n",regs0->SPI_CONFIG);


	//set clock
	div = SPI_CLK_RATE / spi_mas_ctlr[spi_no].freq ;
	div = (div / 2) - 1;

	temp_reg = FD_SEL | ((div & 0xffff) << 16);                     //set up full duplex frequency and enable  full duplex 	
	temp_reg &= CLEAN_RW_BYTE;
	temp_reg |= WRITE_BYTE(0) | READ_BYTE(0) | TX_EMP_FLAG_MASK | FINISH_FLAG_MASK;          // bits_per_word = 8 , data_unit = 1byte
	//temp_reg |= DELAY_ENABLE;

	temp_reg &= CLEAN_SPI_MODE;
	
	switch(spi_mas_ctlr[spi_no].mode){
		case 1:
			temp_reg |= CPHA_W | CPHA_R;
			break;
		case 2:
			temp_reg |= CPOL;  
			break;
		case 3:
			temp_reg |= CPHA_W | CPHA_R;
			temp_reg |= CPOL;  
			break;

		default:
			break;
	}


    regs0->SPI_CONFIG = temp_reg;

     //printf("SPI_CONFIG 0x%x \n",regs0->SPI_CONFIG);	

    // set SPI FIFO data for full duplex (SPI_FD fifo_data)  91.13
    if(spi_mas_ctlr[spi_no].tx_cur_len < len){
        if(len >= 16){
		    for(i=0;i<16;i++){
		   // 
			regs0->FIFO_DATA = spi_mas_ctlr[spi_no].tx_data_buf[i];
			//regs0->FIFO_DATA = 0x12345678;
		    spi_mas_ctlr[spi_no].tx_cur_len++;
	    	}
        }else{
 		    for(i=0;i<len;i++){
				//printf("tx_data_buf1295 0x%x  ,tx_cur_len %d \n",spi_mas_ctlr[spi_no].tx_data_buf[i],spi_mas_ctlr[spi_no].tx_cur_len);
				regs0->FIFO_DATA = spi_mas_ctlr[spi_no].tx_data_buf[i];
				//regs0->FIFO_DATA = 0x12345678;
				spi_mas_ctlr[spi_no].tx_cur_len++;

		    }   
        }
    }


	regs0->SPI_STATUS = TOTAL_LENGTH(len) | TX_LENGTH(len);
	regs0->SPI_STATUS |= SPI_START_FD;


	while((regs0->SPI_STATUS & SPI_BUSY) == SPI_BUSY){
	    if((spi_mas_ctlr[spi_no].tx_cur_len < len) || ((regs0->SPI_STATUS & TX_EMP_FLAG) == TX_EMP_FLAG)){

   	        if((regs0->SPI_STATUS & RX_FULL_FLAG)==RX_FULL_FLAG){
		        for(i=0;i<8;i++){	 // if READ_BYTE(0) i<16  can set the condition at here
			       spi_mas_ctlr[spi_no].rx_data_buf[spi_mas_ctlr[spi_no].rx_cur_len] = regs0->FIFO_DATA;	   
			        spi_mas_ctlr[spi_no].rx_cur_len++;
		        }
	        }

	        while((regs0->SPI_STATUS & RX_CNT )){	
		        spi_mas_ctlr[spi_no].rx_data_buf[spi_mas_ctlr[spi_no].rx_cur_len] = regs0->FIFO_DATA;
		      
		       spi_mas_ctlr[spi_no].rx_cur_len++;
			   if((spi_mas_ctlr[spi_no].tx_cur_len < len) && ((regs0->SPI_STATUS & TX_FULL_FLAG) != TX_FULL_FLAG)){
				  regs0->FIFO_DATA = spi_mas_ctlr[spi_no].tx_data_buf[spi_mas_ctlr[spi_no].tx_cur_len];
				  spi_mas_ctlr[spi_no].tx_cur_len++;
			       //printf("TXcnt221 data 0x%x  tx_cur_len = %d \n",spi_mas_ctlr[spi_no].tx_data_buf[spi_mas_ctlr[spi_no].tx_cur_len],spi_mas_ctlr[spi_no].tx_cur_len);
			   }   
	       }
		
 		    while(len-spi_mas_ctlr[spi_no].tx_cur_len){

				if((regs0->SPI_STATUS & TX_FULL_FLAG) == TX_FULL_FLAG)
			    	break;
				regs0->FIFO_DATA = spi_mas_ctlr[spi_no].tx_data_buf[spi_mas_ctlr[spi_no].tx_cur_len];
				spi_mas_ctlr[spi_no].tx_cur_len++;
		    	//printf("tx_data_buf554 0x%x  ,tx_cur_len %d \n",spi_mas_ctlr[spi_no].tx_data_buf[spi_mas_ctlr[spi_no].tx_cur_len],spi_mas_ctlr[spi_no].tx_cur_len);				
		    }  
		}else if((regs0->SPI_STATUS & RX_FULL_FLAG)==RX_FULL_FLAG){
		    for(i=0;i<8;i++){	 // if READ_BYTE(0) i<16  can set the condition at here
		 	    spi_mas_ctlr[spi_no].rx_data_buf[spi_mas_ctlr[spi_no].rx_cur_len] = regs0->FIFO_DATA;	   
		 	    spi_mas_ctlr[spi_no].rx_cur_len++;
		 	}
		}else {
			while((regs0->SPI_STATUS & RX_CNT )){	
			    spi_mas_ctlr[spi_no].rx_data_buf[spi_mas_ctlr[spi_no].rx_cur_len] = regs0->FIFO_DATA;
				spi_mas_ctlr[spi_no].rx_cur_len++;
			}
		}
	}



	while((regs0->SPI_STATUS & FINISH_FLAG)!=FINISH_FLAG)
	{
		printf("wait finish\n");
	}

	regs0->SPI_CONFIG &= CLEAN_FLUG_MASK;
	regs0->SPI_STATUS |= SPI_SW_RST;
 
	//printf("finish FD write\n");


}

void sp_spi_master_fd_read_write(unsigned int spi_no,u8  *buf, u8  *data_buf , unsigned int len, unsigned int tx_len)
{

	unsigned int temp_reg;
	unsigned int div;
	unsigned int i;
	SPI_MAS_REG * regs0 = (SPI_MAS_REG *)spi_mas_ctlr[spi_no].reg_adr;

	spi_mas_ctlr[spi_no].rx_cur_len = 0 ;
	spi_mas_ctlr[spi_no].tx_cur_len = 0 ;


	memcpy(&spi_mas_ctlr[spi_no].tx_data_buf[0], buf, tx_len);

	//set clock
	div = SPI_CLK_RATE / spi_mas_ctlr[spi_no].freq ;
	div = (div / 2) - 1;

	temp_reg = FD_SEL | ((div & 0xffff) << 16);                     //set up full duplex frequency and enable  full duplex 
	temp_reg &= CLEAN_RW_BYTE;
	temp_reg |= WRITE_BYTE(0) | READ_BYTE(0) | FINISH_FLAG_MASK | TX_EMP_FLAG_MASK | RX_FULL_FLAG_MASK;         // bits_per_word = 8 , data_unit = 1byte
	//temp_reg |= DELAY_ENABLE;

	temp_reg &= CLEAN_SPI_MODE;
	
	switch(spi_mas_ctlr[spi_no].mode){
		case 1:
			temp_reg |= CPHA_W | CPHA_R;
			break;
		case 2:
			temp_reg |= CPOL;  
			break;
		case 3:
			temp_reg |= CPHA_W | CPHA_R;
			temp_reg |= CPOL;  
			break;

		default:
			break;
	}


    regs0->SPI_CONFIG = temp_reg;

	//printf("SPI_CONFIG 0x%x \n",regs0->SPI_CONFIG);    

    // set SPI FIFO data for full duplex (SPI_FD fifo_data)  91.13
    if(spi_mas_ctlr[spi_no].tx_cur_len < tx_len){
        if(tx_len >= 8){
		    for(i=0;i<8;i++){
		    //printf("tx_data_buf1143 0x%x  ,tx_cur_len %d \n",spi_mas_ctlr[spi_no].tx_data_buf[i],spi_mas_ctlr[spi_no].tx_cur_len);
			regs0->FIFO_DATA = spi_mas_ctlr[spi_no].tx_data_buf[i];
		    spi_mas_ctlr[spi_no].tx_cur_len++;
	    	}
        }else{
 		    for(i=0;i<tx_len;i++){
				//printf("tx_data_buf1143 0x%x  ,tx_cur_len %d \n",spi_mas_ctlr[spi_no].tx_data_buf[i],spi_mas_ctlr[spi_no].tx_cur_len);
				regs0->FIFO_DATA = spi_mas_ctlr[spi_no].tx_data_buf[i];
				spi_mas_ctlr[spi_no].tx_cur_len++;

		    }   
        }
    }


	regs0->SPI_STATUS = TOTAL_LENGTH(len) | TX_LENGTH(tx_len);
	regs0->SPI_STATUS |= SPI_START_FD;


	while((regs0->SPI_STATUS & SPI_BUSY) == SPI_BUSY){
		if((spi_mas_ctlr[spi_no].tx_cur_len < tx_len) || ((regs0->SPI_STATUS & TX_EMP_FLAG) == TX_EMP_FLAG)){
			if((regs0->SPI_STATUS & RX_FULL_FLAG)==RX_FULL_FLAG){
				for(i=0;i<8;i++){	 // if READ_BYTE(0) i<16  can set the condition at here
				    spi_mas_ctlr[spi_no].rx_data_buf[spi_mas_ctlr[spi_no].rx_cur_len] = regs0->FIFO_DATA;
				    //printf("RXcnt724 data 0x%x	rx_cur_len = %d \n",spi_mas_ctlr[spi_no].rx_data_buf[spi_mas_ctlr[spi_no].rx_cur_len],spi_mas_ctlr[spi_no].rx_cur_len);		   
				    spi_mas_ctlr[spi_no].rx_cur_len++;
				}
			}
			while((regs0->SPI_STATUS & RX_CNT )){	
				spi_mas_ctlr[spi_no].rx_data_buf[spi_mas_ctlr[spi_no].rx_cur_len] = regs0->FIFO_DATA;
				//printf("RXcnt730 data 0x%x  rx_cur_len = %d \n",spi_mas_ctlr[spi_no].rx_data_buf[spi_mas_ctlr[spi_no].rx_cur_len],spi_mas_ctlr[spi_no].rx_cur_len);
				spi_mas_ctlr[spi_no].rx_cur_len++;
				if((spi_mas_ctlr[spi_no].tx_cur_len < tx_len) && ((regs0->SPI_STATUS & TX_FULL_FLAG) != TX_FULL_FLAG)){
				     regs0->FIFO_DATA = spi_mas_ctlr[spi_no].tx_data_buf[spi_mas_ctlr[spi_no].tx_cur_len];
					 spi_mas_ctlr[spi_no].tx_cur_len++;		   
				}   
		    }
			while(tx_len-spi_mas_ctlr[spi_no].tx_cur_len){
			    //printf("tx_data_buf738 0x%x  ,tx_cur_len %d \n",spi_mas_ctlr[spi_no].tx_data_buf[spi_mas_ctlr[spi_no].tx_cur_len],spi_mas_ctlr[spi_no].tx_cur_len);
			    //printf("tx_len %d  ,tx_cur_len %d \n",tx_len,spi_mas_ctlr[spi_no].tx_cur_len);
			    if((regs0->SPI_STATUS & TX_FULL_FLAG)==TX_FULL_FLAG){
			        break;
			    	}
			        regs0->FIFO_DATA = spi_mas_ctlr[spi_no].tx_data_buf[spi_mas_ctlr[spi_no].tx_cur_len];
					spi_mas_ctlr[spi_no].tx_cur_len++;
			}  
       }else if((regs0->SPI_STATUS & RX_FULL_FLAG)==RX_FULL_FLAG){
	       for(i=0;i<8;i++){	 // if READ_BYTE(0) i<16  can set the condition at here
		       spi_mas_ctlr[spi_no].rx_data_buf[spi_mas_ctlr[spi_no].rx_cur_len] = regs0->FIFO_DATA;
			   //printf("RXcnt748 data 0x%x	rx_cur_len = %d \n",spi_mas_ctlr[spi_no].rx_data_buf[spi_mas_ctlr[spi_no].rx_cur_len],spi_mas_ctlr[spi_no].rx_cur_len);		   
			   spi_mas_ctlr[spi_no].rx_cur_len++;
		    }
	   }else {
	       while((regs0->SPI_STATUS & RX_CNT )){	
		       spi_mas_ctlr[spi_no].rx_data_buf[spi_mas_ctlr[spi_no].rx_cur_len] = regs0->FIFO_DATA;
		       //printf("RXcnt754 data 0x%x	rx_cur_len = %d \n",spi_mas_ctlr[spi_no].rx_data_buf[spi_mas_ctlr[spi_no].rx_cur_len],spi_mas_ctlr[spi_no].rx_cur_len);
		       spi_mas_ctlr[spi_no].rx_cur_len++;
		   }
	   }
	}



	if((regs0->SPI_STATUS & FINISH_FLAG)==FINISH_FLAG){

   	    if((regs0->SPI_STATUS & RX_FULL_FLAG)==RX_FULL_FLAG){
		    for(i=0;i<8;i++){	 // if READ_BYTE(0) i<16  can set the condition at here
			   spi_mas_ctlr[spi_no].rx_data_buf[spi_mas_ctlr[spi_no].rx_cur_len] = regs0->FIFO_DATA;
			   //printf("RXcnt203 data 0x%x	rx_cur_len = %d \n",spi_mas_ctlr[spi_no].rx_data_buf[spi_mas_ctlr[spi_no].rx_cur_len],spi_mas_ctlr[spi_no].rx_cur_len);		   
			    spi_mas_ctlr[spi_no].rx_cur_len++;
		    }
	    }

	    while((regs0->SPI_STATUS & RX_CNT )){	
		    spi_mas_ctlr[spi_no].rx_data_buf[spi_mas_ctlr[spi_no].rx_cur_len] = regs0->FIFO_DATA;
		    printf("RXcnt569 data 0x%x  rx_cur_len = %d \n",spi_mas_ctlr[spi_no].rx_data_buf[spi_mas_ctlr[spi_no].rx_cur_len],spi_mas_ctlr[spi_no].rx_cur_len);
		    spi_mas_ctlr[spi_no].rx_cur_len++;
	    }

	if((tx_len >0) && (spi_mas_ctlr[spi_no].rx_cur_len >= tx_len))
	memcpy(data_buf, &spi_mas_ctlr[spi_no].rx_data_buf[tx_len], (spi_mas_ctlr[spi_no].rx_cur_len-tx_len));
	else
	memcpy(data_buf, &spi_mas_ctlr[spi_no].rx_data_buf[0], spi_mas_ctlr[spi_no].rx_cur_len);

	regs0->SPI_CONFIG &= CLEAN_FLUG_MASK;
	regs0->SPI_STATUS |= SPI_SW_RST;
 
	}


}



void sp_spi_master_fd_read_write_irq(unsigned int spi_no,u8  *buf, u8  *data_buf , unsigned int len, unsigned int tx_len)
{

	unsigned int temp_reg;
	unsigned int div;
	unsigned int i;
	SPI_MAS_REG * regs0 = (SPI_MAS_REG *)spi_mas_ctlr[spi_no].reg_adr;

	spi_mas_ctlr[spi_no].rx_cur_len = 0 ;
	spi_mas_ctlr[spi_no].tx_cur_len = 0 ;


	memcpy(&spi_mas_ctlr[spi_no].tx_data_buf[0], buf, tx_len);

	spi_mas_ctlr[spi_no].buf = data_buf ;
	spi_mas_ctlr[spi_no].len = len ;
	spi_mas_ctlr[spi_no].txlen = tx_len ;	


	//set clock
	div = SPI_CLK_RATE / spi_mas_ctlr[spi_no].freq ;
	div = (div / 2) - 1;

	temp_reg = FD_SEL | ((div & 0xffff) << 16);                     //set up full duplex frequency and enable  full duplex 
	temp_reg &= CLEAN_RW_BYTE;
	temp_reg |= WRITE_BYTE(0) | READ_BYTE(0);         // bits_per_word = 8 , data_unit = 1byte
	//temp_reg |= DELAY_ENABLE;

	temp_reg &= CLEAN_SPI_MODE;
	
	switch(spi_mas_ctlr[spi_no].mode){
		case 1:
			temp_reg |= CPHA_W | CPHA_R;
			break;
		case 2:
			temp_reg |= CPOL;  
			break;
		case 3:
			temp_reg |= CPHA_W | CPHA_R;
			temp_reg |= CPOL;  
			break;

		default:
			break;
	}


    regs0->SPI_CONFIG = temp_reg;


    // set SPI FIFO data for full duplex (SPI_FD fifo_data)  91.13
    if(spi_mas_ctlr[spi_no].tx_cur_len < tx_len){
        if(tx_len >= 8){
		    for(i=0;i<8;i++){
		    //printf("tx_data_buf1143 0x%x  ,tx_cur_len %d \n",spi_mas_ctlr[spi_no].tx_data_buf[i],spi_mas_ctlr[spi_no].tx_cur_len);
			regs0->FIFO_DATA = spi_mas_ctlr[spi_no].tx_data_buf[i];
		    spi_mas_ctlr[spi_no].tx_cur_len++;
	    	}
        }else{
 		    for(i=0;i<tx_len;i++){
				//printf("tx_data_buf1143 0x%x  ,tx_cur_len %d \n",spi_mas_ctlr[spi_no].tx_data_buf[i],spi_mas_ctlr[spi_no].tx_cur_len);
				regs0->FIFO_DATA = spi_mas_ctlr[spi_no].tx_data_buf[i];
				spi_mas_ctlr[spi_no].tx_cur_len++;

}
        }
    }


	//spi_mas_ctlr[spi_no].tx_cur_len =2;


	regs0->SPI_STATUS = TOTAL_LENGTH(len) | TX_LENGTH(tx_len);


	//printf("SPI_STATUS 0x%x \n",regs0->SPI_STATUS);  

	
	regs0->SPI_CONFIG |= FINISH_FLAG_MASK | TX_EMP_FLAG_MASK | RX_FULL_FLAG_MASK;		   // bits_per_word = 8 , data_unit = 1byte
	regs0->SPI_STATUS |= SPI_START_FD;



	//printf("SPI_CONFIG 0x%x \n",regs0->SPI_CONFIG);   
	//printf("SPI_STATUS01 0x%x \n",regs0->SPI_STATUS);   	


}




