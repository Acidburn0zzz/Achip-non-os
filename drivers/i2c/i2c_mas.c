#include <types.h>
#include "common_all.h"
#include "cache.h"




typedef unsigned long long  UINT64  ;
typedef unsigned int        UINT32  ;
typedef unsigned short      UINT16  ;
typedef unsigned char       UINT8   ;


typedef struct regs_i2cm_t_ {
	volatile unsigned int control0;      /* 00 */
	volatile unsigned int control1;      /* 01 */
	volatile unsigned int control2;      /* 02 */
	volatile unsigned int control3;      /* 03 */
	volatile unsigned int control4;      /* 04 */
	volatile unsigned int control5;      /* 05 */
	volatile unsigned int i2cm_status0;  /* 06 */
	volatile unsigned int interrupt;     /* 07 */
	volatile unsigned int int_en0;       /* 08 */
	volatile unsigned int i2cm_mode;     /* 09 */
	volatile unsigned int i2cm_status1;  /* 10 */
	volatile unsigned int i2cm_status2;  /* 11 */
	volatile unsigned int control6;      /* 12 */
	volatile unsigned int int_en1;       /* 13 */
	volatile unsigned int i2cm_status3;  /* 14 */
	volatile unsigned int i2cm_status4;  /* 15 */
	volatile unsigned int int_en2;       /* 16 */
	volatile unsigned int control7;      /* 17 */
	volatile unsigned int control8;      /* 18 */
	volatile unsigned int control9;      /* 19 */
	volatile unsigned int reserved[3];   /* 20~22 */
	volatile unsigned int version;       /* 23 */
	volatile unsigned int data00_03;     /* 24 */
	volatile unsigned int data04_07;     /* 25 */
	volatile unsigned int data08_11;     /* 26 */
	volatile unsigned int data12_15;     /* 27 */
	volatile unsigned int data16_19;     /* 28 */
	volatile unsigned int data20_23;     /* 29 */
	volatile unsigned int data24_27;     /* 30 */
	volatile unsigned int data28_31;     /* 31 */
} I2C_MAS_REG;

typedef	struct regs_i2cm_gdma_s{
	volatile unsigned int hw_version;                /* 00 */
	volatile unsigned int dma_config;                /* 01 */
	volatile unsigned int dma_length;                /* 02 */
	volatile unsigned int dma_addr;                  /* 03 */
	volatile unsigned int port_mux;                  /* 04 */
	volatile unsigned int int_flag;                  /* 05 */
	volatile unsigned int int_en;                    /* 06 */
	volatile unsigned int sw_reset_state;            /* 07 */
	volatile unsigned int reserved[2];               /* 08~09 */
	volatile unsigned int sg_dma_index;              /* 10 */
	volatile unsigned int sg_dma_config;             /* 11 */
	volatile unsigned int sg_dma_length;             /* 12 */
	volatile unsigned int sg_dma_addr;               /* 13 */
	volatile unsigned int reserved2;                 /* 14 */
	volatile unsigned int sg_setting;                /* 15 */
	volatile unsigned int threshold;                 /* 16 */
	volatile unsigned int reserved3;                 /* 17 */
	volatile unsigned int gdma_read_timeout;         /* 18 */
	volatile unsigned int gdma_write_timeout;        /* 19 */
	volatile unsigned int ip_read_timeout;           /* 20 */
	volatile unsigned int ip_write_timeout;          /* 21 */
	volatile unsigned int write_cnt_debug;           /* 22 */
	volatile unsigned int w_byte_en_debug;           /* 23 */
	volatile unsigned int sw_reset_write_cnt_debug;  /* 24 */
	volatile unsigned int reserved4[7];              /* 25~31 */
}I2C_MAS_DMA_REG;

/****************************************
* I2C Master
****************************************/

//control0
#define I2C_CTL0_FREQ(x)                  (x<<24)  //bit[26:24]
#define I2C_CTL0_PREFETCH                 (1<<18)  //Now as read mode need to set high, otherwise don??t care
#define I2C_CTL0_RESTART_EN               (1<<17)  //0:disable 1:enable
#define I2C_CTL0_SUBADDR_EN               (1<<16)  //For restart mode need to set high
#define I2C_CTL0_SW_RESET                 (1<<15)
#define I2C_CTL0_SLAVE_ADDR(x)            (x<<1)   //bit[7:1]

//control1
#define I2C_CTL1_ALL_CLR                  (0x3FF)
#define I2C_CTL1_EMPTY_CLR                (1<<9)
#define I2C_CTL1_SCL_HOLD_TOO_LONG_CLR    (1<<8)
#define I2C_CTL1_SCL_WAIT_CLR             (1<<7)
#define I2C_CTL1_EMPTY_THRESHOLD_CLR      (1<<6)
#define I2C_CTL1_DATA_NACK_CLR            (1<<5)
#define I2C_CTL1_ADDRESS_NACK_CLR         (1<<4)
#define I2C_CTL1_BUSY_CLR                 (1<<3)
#define I2C_CTL1_CLKERR_CLR               (1<<2)
#define I2C_CTL1_DONE_CLR                 (1<<1)
#define I2C_CTL1_SIFBUSY_CLR              (1<<0)

//control2
#define I2C_CTL2_FREQ_CUSTOM(x)           (x<<0)   //bit[10:0]
#define I2C_CTL2_SCL_DELAY(x)             (x<<24)  //bit[25:24]
#define I2C_CTL2_SDA_HALF_ENABLE          (1<<31)

//control5
#define I2C_CTL5_RING_VALUE(x)           (x>>21)   //bit[23:21]
#define I2C_CTL5_STATE(x)                (x>>17)   //bit[20:17]
#define I2C_CTL5_ROBE_MODE(x)            (x>>12)   //bit[15:12]
#define I2C_CTL5_SIFBUSY                 (1<<8)

//control6
#define I2C_CTL6_BURST_RDATA_CLR          I2C_EN1_BURST_RDATA_INT

//control7
#define I2C_CTL7_RDCOUNT(x)               (x<<16)  //bit[31:16]
#define I2C_CTL7_WRCOUNT(x)               (x<<0)   //bit[15:0]

//interrupt
#define I2C_INT_RINC_INDEX(x)             (x<<18)  //bit[20:18]
#define I2C_INT_WINC_INDEX(x)             (x<<15)  //bit[17:15]
#define I2C_INT_SCL_HOLD_TOO_LONG_FLAG    (1<<11)
#define I2C_INT_WFIFO_ENABLE              (1<<10)
#define I2C_INT_FULL_FLAG                 (1<<9)
#define I2C_INT_EMPTY_FLAG                (1<<8)
#define I2C_INT_SCL_WAIT_FLAG             (1<<7)
#define I2C_INT_EMPTY_THRESHOLD_FLAG      (1<<6)
#define I2C_INT_DATA_NACK_FLAG            (1<<5)
#define I2C_INT_ADDRESS_NACK_FLAG         (1<<4)
#define I2C_INT_BUSY_FLAG                 (1<<3)
#define I2C_INT_CLKERR_FLAG               (1<<2)
#define I2C_INT_DONE_FLAG                 (1<<1)
#define I2C_INT_SIFBUSY_FLAG              (1<<0)

//interrupt enable0
#define I2C_EN0_SCL_HOLD_TOO_LONG_INT     (1<<13)
#define I2C_EN0_NACK_INT                  (1<<12)
#define I2C_EN0_CTL_EMPTY_THRESHOLD(x)    (x<<9)  //bit[11:9]
#define I2C_EN0_EMPTY_INT                 (1<<8)
#define I2C_EN0_SCL_WAIT_INT              (1<<7)
#define I2C_EN0_EMPTY_THRESHOLD_INT       (1<<6)
#define I2C_EN0_DATA_NACK_INT             (1<<5)
#define I2C_EN0_ADDRESS_NACK_INT          (1<<4)
#define I2C_EN0_BUSY_INT                  (1<<3)
#define I2C_EN0_CLKERR_INT                (1<<2)
#define I2C_EN0_DONE_INT                  (1<<1)
#define I2C_EN0_SIFBUSY_INT               (1<<0)

#define I2C_CTL0_FREQ_MASK                  (0x7)     // 3 bit
#define I2C_CTL0_SLAVE_ADDR_MASK            (0x7F)    // 7 bit
#define I2C_CTL2_FREQ_CUSTOM_MASK           (0x7FF)   // 11 bit
#define I2C_CTL2_SCL_DELAY_MASK             (0x3)     // 2 bit
#define I2C_CTL7_RW_COUNT_MASK              (0xFFFF)  // 16 bit
#define I2C_EN0_CTL_EMPTY_THRESHOLD_MASK    (0x7)     // 3 bit
#define I2C_SG_DMA_LLI_INDEX_MASK           (0x1F)    // 5 bit

//interrupt enable1
#define I2C_EN1_BURST_RDATA_INT           (0x80008000)  //must sync with GET_BYTES_EACHTIME

//interrupt enable2
#define I2C_EN2_BURST_RDATA_OVERFLOW_INT  (0xFFFFFFFF)

//i2c master mode
#define I2C_MODE_DMA_MODE                 (1<<2)
#define I2C_MODE_MANUAL_MODE              (1<<1)  //0:trigger mode 1:auto mode
#define I2C_MODE_MANUAL_TRIG              (1<<0)

//i2c master status2
#define I2C_SW_RESET_DONE                 (1<<0)


#define I2C_BURST_RDATA_BYTES        16
#define I2C_BURST_RDATA_FLAG         0x80008000
#define I2C_BURST_RDATA_ALL_FLAG     0xFFFFFFFF

/****************************************
* GDMA
****************************************/

//dma config
#define I2C_DMA_CFG_DMA_GO                (1<<8)
#define I2C_DMA_CFG_NON_BUF_MODE          (1<<2)
#define I2C_DMA_CFG_SAME_SLAVE            (1<<1)
#define I2C_DMA_CFG_DMA_MODE              (1<<0)

//dma interrupt flag
#define I2C_DMA_INT_LENGTH0_FLAG          (1<<6)
#define I2C_DMA_INT_THRESHOLD_FLAG        (1<<5)
#define I2C_DMA_INT_IP_TIMEOUT_FLAG       (1<<4)
#define I2C_DMA_INT_GDMA_TIMEOUT_FLAG     (1<<3)
#define I2C_DMA_INT_WB_EN_ERROR_FLAG      (1<<2)
#define I2C_DMA_INT_WCNT_ERROR_FLAG       (1<<1)
#define I2C_DMA_INT_DMA_DONE_FLAG         (1<<0)

//dma interrupt enable
#define I2C_DMA_EN_LENGTH0_INT            (1<<6)
#define I2C_DMA_EN_THRESHOLD_INT          (1<<5)
#define I2C_DMA_EN_IP_TIMEOUT_INT         (1<<4)
#define I2C_DMA_EN_GDMA_TIMEOUT_INT       (1<<3)
#define I2C_DMA_EN_WB_EN_ERROR_INT        (1<<2)
#define I2C_DMA_EN_WCNT_ERROR_INT         (1<<1)
#define I2C_DMA_EN_DMA_DONE_INT           (1<<0)


/****************************************
* SG GDMA
****************************************/

//sg dma index
#define I2C_SG_DMA_LLI_RUN_INDEX(x)       (x<<8)  //bit[12:8]
#define I2C_SG_DMA_LLI_ACCESS_INDEX(x)    (x<<0)  //bit[4:0]

//sg dma config
#define I2C_SG_DMA_CFG_LAST_LLI           (1<<2)
#define I2C_SG_DMA_CFG_DMA_MODE           (1<<0)

//sg dma setting
#define I2C_SG_DMA_SET_DMA_ENABLE         (1<<31)
#define I2C_SG_DMA_SET_DMA_GO             (1<<0)

//volatile regs_i2cm * i2c_regs          = (regs_i2cm *)0x9c004600;
//volatile regs_i2cm_gdma * i2c_dma_regs = (regs_i2cm_gdma *)0x9c004680;


#define I2C_MASTER_NUM         (4)
#define I2C_MSG_DATA_SIZE      (255)


#define I2C_CLK_RATE           202500000
#define I2C_INIT_FREQ          100
#define I2C_MAX_FREQ           400
#define I2C_FREQ               27000


//burst write use
#define I2C_EMPTY_THRESHOLD_VALUE    4



#define I2C_REG_ADDR_0         0x9C004600
#define I2C_REG_ADDR_1         0x9C004700
#define I2C_REG_ADDR_2         0x9C004800
#define I2C_REG_ADDR_3         0x9C004900

#define I2C_DMA_ADDR_0         0x9C004680
#define I2C_DMA_ADDR_1         0x9C004780
#define I2C_DMA_ADDR_2         0x9C004880
#define I2C_DMA_ADDR_3         0x9C004980




static volatile UINT32* grp2_sft_cfg = (UINT32 *) 0x9c000100;
static volatile UINT32* grp3_sft_cfg = (UINT32 *) 0x9c000180;


enum 
{
	I2C_MASTER_0 = 0,
	I2C_MASTER_1 = 1,
	I2C_MASTER_2 = 2,
	I2C_MASTER_3 = 3,
};


typedef enum I2C_State_e_ {
	I2C_WRITE_STATE,  /* i2c is write */
	I2C_READ_STATE,   /* i2c is read */
	I2C_IDLE_STATE,   /* i2c is idle */
	I2C_DMA_WRITE_STATE,/* i2c is dma write */
	I2C_DMA_READ_STATE, /* i2c is dma read */
} I2C_State_e;



struct i2c_master_ctlr {

    unsigned int i2c_ip;
	unsigned int freq;		
	unsigned int reg_adr;
	unsigned int dma_adr;	

    unsigned int rx_cur_len;
    unsigned int tx_cur_len;

	I2C_State_e  RWState;

    unsigned int BurstCount;
    unsigned int BurstRemainder;
    unsigned int DataIndex;
    unsigned int RegDataIndex;
    unsigned int DataTotalLen;


};

struct i2c_master_ctlr i2c_mas_ctlr[I2C_MASTER_NUM];



u8 tx_data_buf[I2C_MASTER_NUM][I2C_MSG_DATA_SIZE];
u8 rx_data_buf[I2C_MASTER_NUM][I2C_MSG_DATA_SIZE];




void sp_i2c_master_set_freq_khz(unsigned int i2c_no, unsigned int freq)
{
     if(i2c_no <= I2C_MASTER_NUM){
	 	if(freq > I2C_MAX_FREQ)
		    i2c_mas_ctlr[i2c_no].freq = I2C_MAX_FREQ;	
	 	else
	 	    i2c_mas_ctlr[i2c_no].freq = freq;
     }

}


void sp_i2c_master_init()
{
	unsigned int i;


	
	printf("sp_i2c_master_init\n");
	
	grp3_sft_cfg[10] = (0x7F7F0000 | (3 << 0) | (4 << 8));	
	
	printf("grp3_sft_cfg[10] %x, grp3_sft_cfg %x\n", grp3_sft_cfg[10], *grp3_sft_cfg);



     for(i=0;i<I2C_MASTER_NUM;i++){
	 	i2c_mas_ctlr[i].i2c_ip = i;
	 	i2c_mas_ctlr[i].freq = I2C_INIT_FREQ;		

		switch(i){
			case 0:
		        i2c_mas_ctlr[0].reg_adr = I2C_REG_ADDR_0;
		        i2c_mas_ctlr[0].dma_adr = I2C_DMA_ADDR_0;		
		        break;
			case 1:
		        i2c_mas_ctlr[1].reg_adr = I2C_REG_ADDR_1;
		        i2c_mas_ctlr[1].dma_adr = I2C_DMA_ADDR_1;				
		        break;
			case 2:
		        i2c_mas_ctlr[2].reg_adr = I2C_REG_ADDR_2;
		        i2c_mas_ctlr[2].dma_adr = I2C_DMA_ADDR_2;				
		        break;
			case 3:
		        i2c_mas_ctlr[3].reg_adr = I2C_REG_ADDR_3;
		        i2c_mas_ctlr[3].dma_adr = I2C_DMA_ADDR_3;					
		        break;
			default:
				break;
		}
		
     }

}


void sp_i2c_data_get(unsigned int device_id, unsigned int index, unsigned int *rdata)
{

	I2C_MAS_REG * i2c_regs = (I2C_MAS_REG *)i2c_mas_ctlr[device_id].reg_adr;


	if (device_id < I2C_MASTER_NUM) {
		switch (index) {
			case 0:
				*rdata = (i2c_regs->data00_03);
				break;
			case 1:
				*rdata = (i2c_regs->data04_07);
				break;
			case 2:
				*rdata = (i2c_regs->data08_11);
				break;
			case 3:
				*rdata = (i2c_regs->data12_15);
				break;
			case 4:
				*rdata = (i2c_regs->data16_19);
				break;
			case 5:
				*rdata = (i2c_regs->data20_23);
				break;
			case 6:
				*rdata = (i2c_regs->data24_27);
				break;
			case 7:
				*rdata = (i2c_regs->data28_31);
				break;
			default:
				break;
		}
		//printk("hal_i2cm_data_get index: %d, data 0x%x\n", index, *rdata);
	}
}



void sp_i2c_data_set(unsigned int device_id, unsigned int *wdata)
{

	I2C_MAS_REG * i2c_regs = (I2C_MAS_REG *)i2c_mas_ctlr[device_id].reg_adr;

	//printf("wdata0 = 0x%x, wdata1 = 0x%x\n", wdata[0], wdata[1]);



	if (device_id < I2C_MASTER_NUM) {
		i2c_regs->data00_03 = wdata[0];
		i2c_regs->data04_07 = wdata[1];
		i2c_regs->data08_11 = wdata[2];
		i2c_regs->data12_15 = wdata[3];
		i2c_regs->data16_19 = wdata[4];
		i2c_regs->data20_23 = wdata[5];
		i2c_regs->data24_27 = wdata[6];
		i2c_regs->data28_31 = wdata[7];
	}
}

void sp_i2c_data0_set(unsigned int device_id, unsigned int *wdata)
{

	I2C_MAS_REG * i2c_regs = (I2C_MAS_REG *)i2c_mas_ctlr[device_id].reg_adr;

	if (device_id < I2C_MASTER_NUM) {
		i2c_regs->data00_03 = wdata[0];
	}
}




void sp_i2c_read(unsigned int i2c_no, u8  slave_addr , u8  *data_buf , unsigned int len)
{

	unsigned int temp_reg;
	unsigned int i,j,k;
	unsigned int status3,bit_index;	
	unsigned int freq;		
    unsigned int ctl0 = 0;	
	unsigned int int0 = 0, int1 = 0, int2 = 0;

	
	I2C_MAS_REG * i2c_regs = (I2C_MAS_REG *)i2c_mas_ctlr[i2c_no].reg_adr;


	//printf("grp3_sft_cfg[10] %x, grp3_sft_cfg %x\n", grp3_sft_cfg[10], *grp3_sft_cfg);
	//printf("i2cread\n");
	//printf("i2c_no : %d, slave_addr: 0x%x , len %d\n", i2c_no, slave_addr,len);
	//printf("sp_i2c_read 0x%x 0x%x\n",i2c_regs,i2c_mas_ctlr[i2c_no].reg_adr);


    i2c_regs->control0 |= I2C_CTL0_SW_RESET ;  // reset 
    //delay_1ms(1);

	int0 = (I2C_EN0_SCL_HOLD_TOO_LONG_INT | I2C_EN0_EMPTY_INT | I2C_EN0_DATA_NACK_INT
			| I2C_EN0_ADDRESS_NACK_INT | I2C_EN0_DONE_INT );	

	int1 = I2C_BURST_RDATA_FLAG;
	int2 = I2C_BURST_RDATA_ALL_FLAG;

	i2c_mas_ctlr[i2c_no].BurstCount = len / I2C_BURST_RDATA_BYTES;
	i2c_mas_ctlr[i2c_no].BurstRemainder = len % I2C_BURST_RDATA_BYTES;
	i2c_mas_ctlr[i2c_no].DataIndex = 0;	
	i2c_mas_ctlr[i2c_no].RegDataIndex = 0;
    i2c_mas_ctlr[i2c_no].RWState = I2C_READ_STATE;
    i2c_mas_ctlr[i2c_no].DataTotalLen = len;

  
    i2c_regs->control0 &= (~I2C_CTL0_FREQ(I2C_CTL0_FREQ_MASK));

	i2c_regs->control2 &= (~I2C_CTL2_FREQ_CUSTOM(I2C_CTL2_FREQ_CUSTOM_MASK));
	freq = (I2C_FREQ / i2c_mas_ctlr[i2c_no].freq) - 1;
	i2c_regs->control2 |= freq;   // 27M/270 =  100k hz


    i2c_regs->control0 &= (~I2C_CTL0_SLAVE_ADDR(I2C_CTL0_SLAVE_ADDR_MASK));
    i2c_regs->control0 |= I2C_CTL0_SLAVE_ADDR(slave_addr);                        // set slave address	

    //i2c_regs->control2 = I2C_CTL7_WRCOUNT(write_cnt) | I2C_CTL7_RDCOUNT(read_cnt);
    i2c_regs->control7  = I2C_CTL7_WRCOUNT(0x00) | I2C_CTL7_RDCOUNT(len);     // set read writer count

	
    i2c_regs->i2cm_mode &= (~(I2C_MODE_MANUAL_MODE | I2C_MODE_MANUAL_TRIG));   // Trigger mode  
    i2c_regs->control0 &= (~(I2C_CTL0_RESTART_EN | I2C_CTL0_SUBADDR_EN));
    i2c_regs->control0 |= I2C_CTL0_PREFETCH;                                   // set read mode


	//printf("control0-3 0x%x \n",i2c_regs->control0);


	i2c_regs->int_en0 = int0;
	i2c_regs->int_en1 = int1;
	i2c_regs->int_en2 = int2;


    i2c_regs->i2cm_mode |= I2C_MODE_MANUAL_TRIG;   // start Trigger 

	while((i2c_regs->interrupt & I2C_INT_DONE_FLAG) != I2C_INT_DONE_FLAG)
	{
	    //printf("i2c_regs->interrupt00 0x%x\n",i2c_regs->interrupt);

        if((i2c_regs->interrupt & I2C_INT_ADDRESS_NACK_FLAG)== I2C_INT_ADDRESS_NACK_FLAG){
		    printf("I2C slave address NACK !!\n");
            break;
		}else if((i2c_regs->interrupt & I2C_INT_DATA_NACK_FLAG)== I2C_INT_DATA_NACK_FLAG){
		    printf("I2C slave data NACK !!\n");
            break;
		}else if((i2c_regs->interrupt & I2C_INT_SCL_HOLD_TOO_LONG_FLAG)== I2C_INT_SCL_HOLD_TOO_LONG_FLAG){
		    printf("I2C SCL hold too long occur !!\n");
            break;
		}


        if(i2c_mas_ctlr[i2c_no].BurstCount){
		    status3 = i2c_regs->i2cm_status3;
		for(i=0;i<(32/I2C_BURST_RDATA_BYTES);i++){    
			bit_index = (I2C_BURST_RDATA_BYTES - 1) + (I2C_BURST_RDATA_BYTES * i);
		    if(status3 & (1 << bit_index)) {
				for (j = 0; j < (I2C_BURST_RDATA_BYTES / 4); j++) {
					k = i2c_mas_ctlr[i2c_no].BurstRemainder + j;
					if (k >= 8) {
						k -= 8;
					}
					sp_i2c_data_get(i2c_no, k, (unsigned int *)(&data_buf[i2c_mas_ctlr[i2c_no].DataIndex]));

					i2c_mas_ctlr[i2c_no].DataIndex += 4;
				}
				i2c_regs->control6 = (((1 << I2C_BURST_RDATA_BYTES) - 1) << (I2C_BURST_RDATA_BYTES * i));
				i2c_regs->control6 = 0;
				i2c_mas_ctlr[i2c_no].RegDataIndex += (I2C_BURST_RDATA_BYTES / 4);
				if (i2c_mas_ctlr[i2c_no].RegDataIndex >= 8) {
					i2c_mas_ctlr[i2c_no].RegDataIndex -= 8;
				}
				i2c_mas_ctlr[i2c_no].BurstCount --;
			
		    }

        }
		}
	};


	//printf("i2c_regs->interrupt01 0x%x\n",i2c_regs->interrupt);

	
	if ((i2c_regs->interrupt & I2C_INT_DONE_FLAG) == I2C_INT_DONE_FLAG) {

		//printf("I2C_INT_DONE_FLAG00 ");
		if ((i2c_mas_ctlr[i2c_no].BurstRemainder)&&(i2c_mas_ctlr[i2c_no].RWState == I2C_READ_STATE)) {
			j = 0;
			for (i = 0; i < (I2C_BURST_RDATA_BYTES / 4); i++) {
				k = i2c_mas_ctlr[i2c_no].RegDataIndex + i;
				if (k >= 8) {
					k -= 8;
				}
				sp_i2c_data_get(i2c_no, k, (unsigned int *)(&rx_data_buf[i2c_no][j]));
				j += 4;
			}
	
			for (i = 0; i < i2c_mas_ctlr[i2c_no].BurstRemainder; i++) {
				i2c_mas_ctlr[i2c_no].DataIndex = i2c_mas_ctlr[i2c_no].DataIndex + i;
				data_buf[i2c_mas_ctlr[i2c_no].DataIndex] =  rx_data_buf[i2c_no][i];			
			}
			//printf("I2C_data i %d ",i);
		}
     }

    i2c_regs->control0 |= I2C_CTL0_SW_RESET ;  // reset 
    i2c_mas_ctlr[i2c_no].RWState = I2C_IDLE_STATE;

	
}


void sp_i2c_write(unsigned int i2c_no, u8  slave_addr , u8  *data_buf , unsigned int len)
{

	unsigned int temp_reg;
	unsigned int i,j,k;
	unsigned int status3,bit_index;	
	unsigned int freq;		
    unsigned int ctl0 = 0;	
	unsigned int int0 = 0, int1 = 0, int2 = 0;
	
	unsigned char w_data[32] = {0};
	unsigned int write_cnt = 0;
	unsigned int burst_cnt = 0;

	
	I2C_MAS_REG * i2c_regs = (I2C_MAS_REG *)i2c_mas_ctlr[i2c_no].reg_adr;


    i2c_regs->control0 |= I2C_CTL0_SW_RESET ;  // reset 
    //delay_1ms(1);

	//printf("data_buf0 = 0x%x, data_buf1 = 0x%x\n", data_buf[0], data_buf[1]);



	write_cnt = len;

	if (write_cnt > 0xFFFF) {
	    printf("I2C write count is invalid !! write count=%d\n", write_cnt);
		//return I2C_ERR_INVALID_CNT;
		  return;
	}

	if (write_cnt > 32) {
		burst_cnt = (write_cnt - 32) / 4;
		if ((write_cnt - 32) % 4) {
			burst_cnt += 1;
		}

		for (i = 0; i < 32; i++) {
			w_data[i] = data_buf[i];
		}
	} else {
		for(i = 0; i < write_cnt; i++){
			w_data[i] = data_buf[i];
		}
	}
	//printf("write_cnt = %d, burst_cnt = %d\n", write_cnt, burst_cnt);

	int0 = (I2C_EN0_SCL_HOLD_TOO_LONG_INT | I2C_EN0_EMPTY_INT | I2C_EN0_DATA_NACK_INT
			| I2C_EN0_ADDRESS_NACK_INT | I2C_EN0_DONE_INT );

	if (burst_cnt)
	    int0 |= I2C_EN0_EMPTY_THRESHOLD_INT;


	i2c_mas_ctlr[i2c_no].RWState = I2C_WRITE_STATE;
	i2c_mas_ctlr[i2c_no].BurstCount = burst_cnt;
	i2c_mas_ctlr[i2c_no].DataIndex = i;
	i2c_mas_ctlr[i2c_no].DataTotalLen = write_cnt;

    i2c_regs->control0 &= (~I2C_CTL0_FREQ(I2C_CTL0_FREQ_MASK));

	i2c_regs->control2 &= (~I2C_CTL2_FREQ_CUSTOM(I2C_CTL2_FREQ_CUSTOM_MASK));
	freq = (I2C_FREQ / i2c_mas_ctlr[i2c_no].freq) - 1;
	i2c_regs->control2 |= freq;   // 27M/270 =  100k hz


	
    i2c_regs->control0 &= (~I2C_CTL0_SLAVE_ADDR(I2C_CTL0_SLAVE_ADDR_MASK));
     //i2c_regs->control0 |= I2C_CTL0_SLAVE_ADDR(t_addr);                        // set slave address
    i2c_regs->control0 |= I2C_CTL0_SLAVE_ADDR(slave_addr);                        // set slave address	

     //i2c_regs->control2 = I2C_CTL7_WRCOUNT(write_cnt) | I2C_CTL7_RDCOUNT(read_cnt);
    i2c_regs->control7  = I2C_CTL7_WRCOUNT(len) | I2C_CTL7_RDCOUNT(0x00);     // set read writer count
    i2c_regs->i2cm_mode &= (~(I2C_MODE_MANUAL_MODE | I2C_MODE_MANUAL_TRIG));   // Trigger mode  

    i2c_regs->control0 &= (~(I2C_CTL0_PREFETCH | I2C_CTL0_RESTART_EN | I2C_CTL0_SUBADDR_EN));  // i2c write mode

	sp_i2c_data_set(i2c_no, (unsigned int *)w_data);

    i2c_regs->int_en0 = (int0 | I2C_EN0_CTL_EMPTY_THRESHOLD(I2C_EMPTY_THRESHOLD_VALUE));

    i2c_regs->i2cm_mode |= I2C_MODE_MANUAL_TRIG;   // start Trigger 

	while((i2c_regs->interrupt & I2C_INT_DONE_FLAG) != I2C_INT_DONE_FLAG){
		
	   // printf("i2c_regs->interrupt 0x%x\n",i2c_regs->interrupt);

        if((i2c_regs->interrupt & I2C_INT_ADDRESS_NACK_FLAG) == I2C_INT_ADDRESS_NACK_FLAG){
		    printf("I2C slave address NACK !!\n");
            break;
		}else if((i2c_regs->interrupt & I2C_INT_DATA_NACK_FLAG) == I2C_INT_DATA_NACK_FLAG){
		    printf("I2C slave data NACK !!\n");
            break;
		}else if((i2c_regs->interrupt & I2C_INT_SCL_HOLD_TOO_LONG_FLAG) == I2C_INT_SCL_HOLD_TOO_LONG_FLAG){
		    printf("I2C SCL hold too long occur !!\n");
            break;
		}
		
        if((i2c_regs->interrupt & I2C_INT_EMPTY_THRESHOLD_FLAG) == I2C_INT_EMPTY_THRESHOLD_FLAG){
		    for (i = 0; i < I2C_EMPTY_THRESHOLD_VALUE; i++) {
			    for (j = 0; j < 4; j++) {
				    if (i2c_mas_ctlr[i2c_no].DataIndex >= i2c_mas_ctlr[i2c_no].DataTotalLen) {
					    w_data[j] = 0;
					} else {
						w_data[j] = data_buf[i2c_mas_ctlr[i2c_no].DataIndex];
					}
					    i2c_mas_ctlr[i2c_no].DataIndex++;
				}
				sp_i2c_data0_set(i2c_no, (unsigned int *)w_data);
				i2c_mas_ctlr[i2c_no].BurstCount--;
								
				if (i2c_mas_ctlr[i2c_no].BurstCount == 0) {
				    i2c_regs->int_en0 &=	(~(I2C_EN0_EMPTY_THRESHOLD_INT | I2C_EN0_EMPTY_INT));
				    break;
				}
		   }
		i2c_regs->control1 |= I2C_CTL1_EMPTY_THRESHOLD_CLR;
		i2c_regs->control1 &= ~(I2C_CTL1_EMPTY_THRESHOLD_CLR);

	    }

	}


    i2c_regs->control0 |= I2C_CTL0_SW_RESET ;  // reset 
    i2c_mas_ctlr[i2c_no].RWState = I2C_IDLE_STATE;


}


void sp_i2c_dma_read(unsigned int i2c_no, u8  slave_addr , u8  *data_buf , unsigned int len)

{

	unsigned int temp_reg;
	unsigned int i,j,k;
    unsigned int data_len = 0;	
	unsigned int freq;		
	unsigned int int0 = 0, int1 = 0, int2 = 0;

	
	I2C_MAS_REG * i2c_regs = (I2C_MAS_REG *)i2c_mas_ctlr[i2c_no].reg_adr;
	I2C_MAS_DMA_REG * i2c_dma_regs = (I2C_MAS_DMA_REG *)i2c_mas_ctlr[i2c_no].dma_adr;	


    i2c_regs->control0 |= I2C_CTL0_SW_RESET ;  // reset 
    //delay_1ms(1);

	int0 = (I2C_EN0_SCL_HOLD_TOO_LONG_INT | I2C_EN0_EMPTY_INT | I2C_EN0_DATA_NACK_INT
			| I2C_EN0_ADDRESS_NACK_INT | I2C_EN0_DONE_INT );	

	int1 = I2C_BURST_RDATA_FLAG;
	int2 = I2C_BURST_RDATA_ALL_FLAG;

	i2c_mas_ctlr[i2c_no].BurstCount = len / I2C_BURST_RDATA_BYTES;
	i2c_mas_ctlr[i2c_no].BurstRemainder = len % I2C_BURST_RDATA_BYTES;
	i2c_mas_ctlr[i2c_no].DataIndex = 0;	
	i2c_mas_ctlr[i2c_no].RegDataIndex = 0;
    i2c_mas_ctlr[i2c_no].RWState = I2C_DMA_READ_STATE;
    i2c_mas_ctlr[i2c_no].DataTotalLen = len;

	i2c_regs->i2cm_mode |= I2C_MODE_DMA_MODE;  // enable DMA

    i2c_regs->control0 &= (~I2C_CTL0_FREQ(I2C_CTL0_FREQ_MASK));

	i2c_regs->control2 &= (~I2C_CTL2_FREQ_CUSTOM(I2C_CTL2_FREQ_CUSTOM_MASK));
	freq = (I2C_FREQ / i2c_mas_ctlr[i2c_no].freq) - 1;
	i2c_regs->control2 |= freq;   // 27M/270 =  100k hz


	i2c_regs->control2 &= (~I2C_CTL2_SCL_DELAY(I2C_CTL2_SCL_DELAY_MASK));
	i2c_regs->control2 |= I2C_CTL2_SCL_DELAY(0x01);
    i2c_regs->control2 &= (~(I2C_CTL2_SDA_HALF_ENABLE));


    i2c_regs->control0 &= (~I2C_CTL0_SLAVE_ADDR(I2C_CTL0_SLAVE_ADDR_MASK));
    //i2c_regs->control0 |= I2C_CTL0_SLAVE_ADDR(t_addr);                        // set slave address
    i2c_regs->control0 |= I2C_CTL0_SLAVE_ADDR(slave_addr);                        // set slave address	

    i2c_regs->i2cm_mode &= (~(I2C_MODE_MANUAL_MODE | I2C_MODE_MANUAL_TRIG));   // clear mode  
    i2c_regs->i2cm_mode |= I2C_MODE_MANUAL_MODE;                               //set AUTO mode

    i2c_regs->control0 &= (~(I2C_CTL0_RESTART_EN | I2C_CTL0_SUBADDR_EN));
    i2c_regs->control0 |= I2C_CTL0_PREFETCH;                                   // set read mode

    i2c_regs->int_en0 = int0;
    i2c_regs->int_en1 = int1;
    i2c_regs->int_en2 = int2;

	
    if(len < 4)
        i2c_dma_regs->dma_length = 4; 		
    else
        i2c_dma_regs->dma_length = len; 	


     HAL_DCACHE_INVALIDATE(data_buf,len);   // cache data map to dram   

    i2c_dma_regs->dma_addr = (unsigned int)data_buf;  
    i2c_dma_regs->dma_config |= I2C_DMA_CFG_DMA_MODE;
    i2c_dma_regs->int_en = I2C_DMA_EN_DMA_DONE_INT; 
    i2c_dma_regs->dma_config |= I2C_DMA_CFG_DMA_GO;


	//printf("dma_config 0x%x \n",i2c_dma_regs->dma_config);
	//printf("i2cm_control2 0x%x \n",i2c_regs->control2);
	//printf("i2cm_control0 0x%x \n",i2c_regs->control0);
	//printf("i2cm_mode 0x%x \n",i2c_regs->i2cm_mode);
	//printf("dma_addr 0x%x \n",i2c_dma_regs->dma_addr);		
	//printf("dma_length 0x%x \n",i2c_dma_regs->dma_length);
	//printf("int_flag 0x%x \n",i2c_regs->interrupt);
	//printf("dma_int_flag 0x%x \n",i2c_dma_regs->int_flag);

	while((i2c_regs->control5 & I2C_CTL5_SIFBUSY) == I2C_CTL5_SIFBUSY)
	{

        if((i2c_regs->interrupt & I2C_INT_ADDRESS_NACK_FLAG)== I2C_INT_ADDRESS_NACK_FLAG){
		    printf("I2C slave address NACK !!\n");
            break;
		}else if((i2c_regs->interrupt & I2C_INT_DATA_NACK_FLAG)== I2C_INT_DATA_NACK_FLAG){
		    printf("I2C slave data NACK !!\n");
            break;
		}else if((i2c_regs->interrupt & I2C_INT_SCL_HOLD_TOO_LONG_FLAG)== I2C_INT_SCL_HOLD_TOO_LONG_FLAG){
		    printf("I2C SCL hold too long occur !!\n");
            break;
		}	   

	}

	while(((i2c_regs->interrupt & I2C_INT_DONE_FLAG) != I2C_INT_DONE_FLAG) && ((i2c_dma_regs->int_flag & I2C_DMA_INT_DMA_DONE_FLAG) != I2C_DMA_INT_DMA_DONE_FLAG))
	{
	    printf("i2c_dma_regs->int_flag 0x%x\n",i2c_dma_regs->int_flag);

        if((i2c_dma_regs->int_flag & I2C_DMA_INT_WCNT_ERROR_FLAG) == I2C_DMA_INT_WCNT_ERROR_FLAG){
		    printf("I2C DMA WCNT ERR !!\n");
            break;
		}else if((i2c_dma_regs->int_flag & I2C_DMA_INT_WB_EN_ERROR_FLAG) == I2C_DMA_INT_WB_EN_ERROR_FLAG){
		    printf("I2C DMA WB EN ERR !!\n");
            break;
		}else if((i2c_dma_regs->int_flag & I2C_DMA_INT_GDMA_TIMEOUT_FLAG) == I2C_DMA_INT_GDMA_TIMEOUT_FLAG){
		    printf("I2C DMA timeout !!\n");
            break;
		}else if((i2c_dma_regs->int_flag & I2C_DMA_INT_IP_TIMEOUT_FLAG) == I2C_DMA_INT_IP_TIMEOUT_FLAG){
		    printf("I2C IP timeout !!\n");
            break;
		}else if((i2c_dma_regs->int_flag & I2C_DMA_INT_THRESHOLD_FLAG) == I2C_DMA_INT_THRESHOLD_FLAG){
		    printf("I2C Length is zero !!\n");
            break;
		}

	};

    //HAL_DCACHE_INVALIDATE(data_buf,len);   // cache data map to dram   

    i2c_regs->control0 |= I2C_CTL0_SW_RESET ;  // reset 
    i2c_mas_ctlr[i2c_no].RWState = I2C_IDLE_STATE;


}



void sp_i2c_dma_write(unsigned int i2c_no, u8  slave_addr , u8  *data_buf , unsigned int len)

{

	unsigned int temp_reg;
	unsigned int i=0,j,k;
    unsigned int data_len = 0;
	unsigned int freq;		
	unsigned int int0 = 0, int1 = 0, int2 = 0;
	unsigned int burst_cnt = 0;	

	
	I2C_MAS_REG * i2c_regs = (I2C_MAS_REG *)i2c_mas_ctlr[i2c_no].reg_adr;
	I2C_MAS_DMA_REG * i2c_dma_regs = (I2C_MAS_DMA_REG *)i2c_mas_ctlr[i2c_no].dma_adr;	


    i2c_regs->control0 |= I2C_CTL0_SW_RESET ;  // reset 
    //delay_1ms(1);

	//printf("data_buf0 = 0x%x, data_buf1 = 0x%x\n", data_buf[0], data_buf[1]);	
	//printf("data_bufW00_addr:%x\n ",data_buf);
	//printf("sp_i2c_write 0x%x 0x%x\n",i2c_regs,i2c_dma_regs);


	int0 = (I2C_EN0_SCL_HOLD_TOO_LONG_INT | I2C_EN0_EMPTY_INT | I2C_EN0_DATA_NACK_INT
			| I2C_EN0_ADDRESS_NACK_INT | I2C_EN0_DONE_INT );

	if (burst_cnt)
	    int0 |= I2C_EN0_EMPTY_THRESHOLD_INT;

	i2c_mas_ctlr[i2c_no].RWState = I2C_DMA_WRITE_STATE;
	i2c_mas_ctlr[i2c_no].BurstCount = burst_cnt;
	i2c_mas_ctlr[i2c_no].DataIndex = i;
	i2c_mas_ctlr[i2c_no].DataTotalLen = len;

	i2c_regs->i2cm_mode |= I2C_MODE_DMA_MODE;  // enable DMA

    i2c_regs->control0 &= (~I2C_CTL0_FREQ(I2C_CTL0_FREQ_MASK));

	i2c_regs->control2 &= (~I2C_CTL2_FREQ_CUSTOM(I2C_CTL2_FREQ_CUSTOM_MASK));
	freq = (I2C_FREQ / i2c_mas_ctlr[i2c_no].freq) - 1;
	i2c_regs->control2 |= freq;   // 27M/270 =  100k hz
	
    i2c_regs->control0 &= (~I2C_CTL0_SLAVE_ADDR(I2C_CTL0_SLAVE_ADDR_MASK));
     //i2c_regs->control0 |= I2C_CTL0_SLAVE_ADDR(t_addr);                        // set slave address
    i2c_regs->control0 |= I2C_CTL0_SLAVE_ADDR(slave_addr);                        // set slave address	

    i2c_regs->i2cm_mode &= (~(I2C_MODE_MANUAL_MODE | I2C_MODE_MANUAL_TRIG));
	i2c_regs->i2cm_mode |= I2C_MODE_MANUAL_MODE;	// AUTO mode  

    i2c_regs->control0 &= (~(I2C_CTL0_PREFETCH | I2C_CTL0_RESTART_EN | I2C_CTL0_SUBADDR_EN));  // i2c write mode

    i2c_regs->int_en0 = int0 ;

	HAL_DCACHE_FLUSH(data_buf,len);   // cache data map to dram

    if(len < 4)
        i2c_dma_regs->dma_length = 4; 		
    else
        i2c_dma_regs->dma_length = len; 	

    i2c_dma_regs->dma_addr = (unsigned int) data_buf;  
    i2c_dma_regs->dma_config &=~(I2C_DMA_CFG_DMA_MODE);
    i2c_dma_regs->int_en = I2C_DMA_EN_DMA_DONE_INT; 
    i2c_dma_regs->dma_config |= I2C_DMA_CFG_DMA_GO;



	//printf("i2cm_control2 0x%x \n",i2c_regs->control2);
	//printf("i2cm_control0 0x%x \n",i2c_regs->control0);
	//printf("i2cm_mode 0x%x \n",i2c_regs->i2cm_mode);
	//printf("dma_config 0x%x \n",i2c_dma_regs->dma_config);
	//printf("dma_addr 0x%x \n",i2c_dma_regs->dma_addr);
	//i2c_dma_regs->dma_config |= I2C_DMA_CFG_DMA_GO;
	//printf("dma_length 0x%x \n",i2c_dma_regs->dma_length);	



	while(((i2c_regs->interrupt & I2C_INT_DONE_FLAG) != I2C_INT_DONE_FLAG) && ((i2c_dma_regs->int_flag & I2C_DMA_INT_DMA_DONE_FLAG) != I2C_DMA_INT_DMA_DONE_FLAG))
	{
	    printf("i2c_dma_regs->int_flag 0x%x\n",i2c_dma_regs->int_flag);

        if((i2c_dma_regs->int_flag & I2C_DMA_INT_WCNT_ERROR_FLAG) == I2C_DMA_INT_WCNT_ERROR_FLAG){
		    printf("I2C DMA WCNT ERR !!\n");
            break;
		}else if((i2c_dma_regs->int_flag & I2C_DMA_INT_WB_EN_ERROR_FLAG) == I2C_DMA_INT_WB_EN_ERROR_FLAG){
		    printf("I2C DMA WB EN ERR !!\n");
            break;
		}else if((i2c_dma_regs->int_flag & I2C_DMA_INT_GDMA_TIMEOUT_FLAG) == I2C_DMA_INT_GDMA_TIMEOUT_FLAG){
		    printf("I2C DMA timeout !!\n");
            break;
		}else if((i2c_dma_regs->int_flag & I2C_DMA_INT_IP_TIMEOUT_FLAG) == I2C_DMA_INT_IP_TIMEOUT_FLAG){
		    printf("I2C IP timeout !!\n");
            break;
		}else if((i2c_dma_regs->int_flag & I2C_DMA_INT_THRESHOLD_FLAG) == I2C_DMA_INT_THRESHOLD_FLAG){
		    printf("I2C Length is zero !!\n");
            break;
		}

	};

	while((i2c_regs->control5 & I2C_CTL5_SIFBUSY) == I2C_CTL5_SIFBUSY)
	{

        if((i2c_regs->interrupt & I2C_INT_ADDRESS_NACK_FLAG)== I2C_INT_ADDRESS_NACK_FLAG){
		    printf("I2C slave address NACK !!\n");
            break;
		}else if((i2c_regs->interrupt & I2C_INT_DATA_NACK_FLAG)== I2C_INT_DATA_NACK_FLAG){
		    printf("I2C slave data NACK !!\n");
            break;
		}else if((i2c_regs->interrupt & I2C_INT_SCL_HOLD_TOO_LONG_FLAG)== I2C_INT_SCL_HOLD_TOO_LONG_FLAG){
		    printf("I2C SCL hold too long occur !!\n");
            break;
		}

	}

    i2c_regs->control0 |= I2C_CTL0_SW_RESET ;  // reset 
    i2c_mas_ctlr[i2c_no].RWState = I2C_IDLE_STATE;



}




