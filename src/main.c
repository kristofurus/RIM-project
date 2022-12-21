#include "xparameters.h"
#include "xil_printf.h"
#include "xgpio.h"
#include "xil_types.h"
#include "xsysmon.h"

// UART params
// baud rate: 	115200
// data bits:	8
// parity: 		None

// xadc params

#define XADC_ID XPAR_XADC_WIZ_0_DEVICE_ID 	// xadc id
// available channels
#define XADC_VAUX6 XSM_CH_AUX_MIN+6			// vaux6 (connector JXADC1 & JXADC7)
#define XADC_VAUX7 XSM_CH_AUX_MIN+7			// vaux7 (connector JXADC3 & JXADC9)
#define XADC_VAUX14 XSM_CH_AUX_MIN+14		// vaux14 (connector JXADC2 & JXADC8)
#define XADC_VAUX15 XSM_CH_AUX_MIN+15		// vaux15 (connector JXADC4 & JXADC10)

// button params
#define BTN_ID XPAR_AXI_GPIO_BUTTONS_DEVICE_ID	// buttons id
#define BTN_CHANNEL 1							// button channel
#define BTN_MASK 0b1111							// buttons mask (1 - on, 0 - off)

int main() {

	// Sysmon (xadc) configuration variables
	XSysMon_Config *sys_cfg_ptr;
	XSysMon adc_device;
	u16 adc_data[4];

	// first UART transmission
	xil_printf("Entered function main\r\n");

	// Initialize Sysmon (xadc)
	sys_cfg_ptr = XSysMon_LookupConfig(XADC_ID);
	XSysMon_CfgInitialize(&adc_device, sys_cfg_ptr, sys_cfg_ptr->BaseAddress);

	XSysMon_StartAdcConversion(&adc_device);

	while (1) {
		adc_data[0] = XSysMon_GetAdcData(&adc_device, XADC_VAUX6);
		adc_data[1] = XSysMon_GetAdcData(&adc_device, XADC_VAUX14);
		adc_data[2] = XSysMon_GetAdcData(&adc_device, XADC_VAUX7);
		adc_data[3] = XSysMon_GetAdcData(&adc_device, XADC_VAUX15);
		xil_printf("%u\t%u\t%u\t%u\r\n", adc_data[0], adc_data[1], adc_data[2], adc_data[3]);

	}
}
