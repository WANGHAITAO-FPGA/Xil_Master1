// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VEndat_SPI_Ctrl__Syms.h"


//======================

void VEndat_SPI_Ctrl::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addCallback(&VEndat_SPI_Ctrl::traceInit, &VEndat_SPI_Ctrl::traceFull, &VEndat_SPI_Ctrl::traceChg, this);
}
void VEndat_SPI_Ctrl::traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->open()
    VEndat_SPI_Ctrl* t = (VEndat_SPI_Ctrl*)userthis;
    VEndat_SPI_Ctrl__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vcdp->scopeEscape(' ');
    t->traceInitThis(vlSymsp, vcdp, code);
    vcdp->scopeEscape('.');
}
void VEndat_SPI_Ctrl::traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    VEndat_SPI_Ctrl* t = (VEndat_SPI_Ctrl*)userthis;
    VEndat_SPI_Ctrl__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    t->traceFullThis(vlSymsp, vcdp, code);
}

//======================


void VEndat_SPI_Ctrl::traceInitThis(VEndat_SPI_Ctrl__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VEndat_SPI_Ctrl* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    vcdp->module(vlSymsp->name());  // Setup signal names
    // Body
    {
        vlTOPp->traceInitThis__1(vlSymsp, vcdp, code);
    }
}

void VEndat_SPI_Ctrl::traceFullThis(VEndat_SPI_Ctrl__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VEndat_SPI_Ctrl* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vlTOPp->traceFullThis__1(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void VEndat_SPI_Ctrl::traceInitThis__1(VEndat_SPI_Ctrl__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VEndat_SPI_Ctrl* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->declBus(c+857,"spi_ss", false,-1, 0,0);
        vcdp->declBit(c+865,"spi_sclk", false,-1);
        vcdp->declBit(c+873,"spi_mosi", false,-1);
        vcdp->declBit(c+881,"spi_miso", false,-1);
        vcdp->declBit(c+889,"cmddata_valid", false,-1);
        vcdp->declBus(c+897,"cmddata_payload_Identity_Addr", false,-1, 15,0);
        vcdp->declBus(c+905,"cmddata_payload_CmdData_0", false,-1, 15,0);
        vcdp->declBus(c+913,"cmddata_payload_CmdData_1", false,-1, 15,0);
        vcdp->declBus(c+921,"cmddata_payload_CmdData_2", false,-1, 15,0);
        vcdp->declBus(c+929,"cmddata_payload_CmdData_3", false,-1, 15,0);
        vcdp->declBus(c+937,"cmddata_payload_Bytenumber", false,-1, 5,0);
        vcdp->declBit(c+945,"rspdata_valid", false,-1);
        vcdp->declBus(c+953,"rspdata_payload_RspData_0", false,-1, 15,0);
        vcdp->declBus(c+961,"rspdata_payload_RspData_1", false,-1, 15,0);
        vcdp->declBus(c+969,"rspdata_payload_RspData_2", false,-1, 15,0);
        vcdp->declBus(c+977,"rspdata_payload_RspData_3", false,-1, 15,0);
        vcdp->declBus(c+985,"rspdata_payload_RspData_4", false,-1, 15,0);
        vcdp->declBit(c+993,"clk", false,-1);
        vcdp->declBit(c+1001,"reset", false,-1);
        vcdp->declBus(c+857,"Endat_SPI_Ctrl spi_ss", false,-1, 0,0);
        vcdp->declBit(c+865,"Endat_SPI_Ctrl spi_sclk", false,-1);
        vcdp->declBit(c+873,"Endat_SPI_Ctrl spi_mosi", false,-1);
        vcdp->declBit(c+881,"Endat_SPI_Ctrl spi_miso", false,-1);
        vcdp->declBit(c+889,"Endat_SPI_Ctrl cmddata_valid", false,-1);
        vcdp->declBus(c+897,"Endat_SPI_Ctrl cmddata_payload_Identity_Addr", false,-1, 15,0);
        vcdp->declBus(c+905,"Endat_SPI_Ctrl cmddata_payload_CmdData_0", false,-1, 15,0);
        vcdp->declBus(c+913,"Endat_SPI_Ctrl cmddata_payload_CmdData_1", false,-1, 15,0);
        vcdp->declBus(c+921,"Endat_SPI_Ctrl cmddata_payload_CmdData_2", false,-1, 15,0);
        vcdp->declBus(c+929,"Endat_SPI_Ctrl cmddata_payload_CmdData_3", false,-1, 15,0);
        vcdp->declBus(c+937,"Endat_SPI_Ctrl cmddata_payload_Bytenumber", false,-1, 5,0);
        vcdp->declBit(c+945,"Endat_SPI_Ctrl rspdata_valid", false,-1);
        vcdp->declBus(c+953,"Endat_SPI_Ctrl rspdata_payload_RspData_0", false,-1, 15,0);
        vcdp->declBus(c+961,"Endat_SPI_Ctrl rspdata_payload_RspData_1", false,-1, 15,0);
        vcdp->declBus(c+969,"Endat_SPI_Ctrl rspdata_payload_RspData_2", false,-1, 15,0);
        vcdp->declBus(c+977,"Endat_SPI_Ctrl rspdata_payload_RspData_3", false,-1, 15,0);
        vcdp->declBus(c+985,"Endat_SPI_Ctrl rspdata_payload_RspData_4", false,-1, 15,0);
        vcdp->declBit(c+993,"Endat_SPI_Ctrl clk", false,-1);
        vcdp->declBit(c+1001,"Endat_SPI_Ctrl reset", false,-1);
        vcdp->declBus(c+1009,"Endat_SPI_Ctrl fsm_enumDef_BOOT", false,-1, 2,0);
        vcdp->declBus(c+1017,"Endat_SPI_Ctrl fsm_enumDef_Init_Start", false,-1, 2,0);
        vcdp->declBus(c+1025,"Endat_SPI_Ctrl fsm_enumDef_Send_Identity_Addr", false,-1, 2,0);
        vcdp->declBus(c+1033,"Endat_SPI_Ctrl fsm_enumDef_Send_RegData", false,-1, 2,0);
        vcdp->declBus(c+1041,"Endat_SPI_Ctrl fsm_enumDef_Wait_Rsp", false,-1, 2,0);
        vcdp->declBus(c+1049,"Endat_SPI_Ctrl fsm_enumDef_Rd_Rsp", false,-1, 2,0);
        vcdp->declBit(c+481,"Endat_SPI_Ctrl spictrl_spi_sclk", false,-1);
        vcdp->declBit(c+489,"Endat_SPI_Ctrl spictrl_spi_mosi", false,-1);
        vcdp->declBus(c+649,"Endat_SPI_Ctrl spictrl_spi_ss", false,-1, 0,0);
        vcdp->declBit(c+1,"Endat_SPI_Ctrl spictrl_cmd_ready", false,-1);
        vcdp->declBit(c+9,"Endat_SPI_Ctrl spictrl_rsp_valid", false,-1);
        vcdp->declBus(c+497,"Endat_SPI_Ctrl spictrl_rsp_payload", false,-1, 15,0);
        vcdp->declBus(c+17,"Endat_SPI_Ctrl spictrl_occupancy", false,-1, 6,0);
        vcdp->declBit(c+1057,"Endat_SPI_Ctrl fsm_wantExit", false,-1);
        vcdp->declBit(c+25,"Endat_SPI_Ctrl fsm_wantStart", false,-1);
        vcdp->declBit(c+1057,"Endat_SPI_Ctrl fsm_wantKill", false,-1);
        vcdp->declBus(c+657,"Endat_SPI_Ctrl fsm_Identity_Addr", false,-1, 15,0);
        vcdp->declBus(c+505,"Endat_SPI_Ctrl fsm_CmdData_0", false,-1, 15,0);
        vcdp->declBus(c+513,"Endat_SPI_Ctrl fsm_CmdData_1", false,-1, 15,0);
        vcdp->declBus(c+521,"Endat_SPI_Ctrl fsm_CmdData_2", false,-1, 15,0);
        vcdp->declBus(c+529,"Endat_SPI_Ctrl fsm_CmdData_3", false,-1, 15,0);
        vcdp->declBus(c+537,"Endat_SPI_Ctrl fsm_Cycle", false,-1, 1,0);
        vcdp->declBus(c+665,"Endat_SPI_Ctrl fsm_counter", false,-1, 3,0);
        vcdp->declBit(c+545,"Endat_SPI_Ctrl fsm_rdfifo_ready", false,-1);
        vcdp->declBit(c+553,"Endat_SPI_Ctrl fsm_spi_cmd_valid", false,-1);
        vcdp->declBus(c+673,"Endat_SPI_Ctrl fsm_spi_cmd_payload", false,-1, 15,0);
        vcdp->declBus(c+561,"Endat_SPI_Ctrl fsm_rspData_0", false,-1, 15,0);
        vcdp->declBus(c+569,"Endat_SPI_Ctrl fsm_rspData_1", false,-1, 15,0);
        vcdp->declBus(c+577,"Endat_SPI_Ctrl fsm_rspData_2", false,-1, 15,0);
        vcdp->declBus(c+585,"Endat_SPI_Ctrl fsm_rspData_3", false,-1, 15,0);
        vcdp->declBus(c+593,"Endat_SPI_Ctrl fsm_rspData_4", false,-1, 15,0);
        vcdp->declBus(c+681,"Endat_SPI_Ctrl fsm_stateReg", false,-1, 2,0);
        vcdp->declBus(c+393,"Endat_SPI_Ctrl fsm_stateNext", false,-1, 2,0);
        vcdp->declBit(c+33,"Endat_SPI_Ctrl when_Endat_SPI_Ctrl_l183", false,-1);
        vcdp->declBit(c+41,"Endat_SPI_Ctrl when_Endat_SPI_Ctrl_l196", false,-1);
        vcdp->declBit(c+49,"Endat_SPI_Ctrl when_Endat_SPI_Ctrl_l204", false,-1);
        vcdp->declBit(c+57,"Endat_SPI_Ctrl when_Endat_SPI_Ctrl_l208", false,-1);
        vcdp->declArray(c+65,"Endat_SPI_Ctrl fsm_stateReg_string", false,-1, 143,0);
        vcdp->declArray(c+401,"Endat_SPI_Ctrl fsm_stateNext_string", false,-1, 143,0);
        vcdp->declBus(c+649,"Endat_SPI_Ctrl spictrl spi_ss", false,-1, 0,0);
        vcdp->declBit(c+481,"Endat_SPI_Ctrl spictrl spi_sclk", false,-1);
        vcdp->declBit(c+489,"Endat_SPI_Ctrl spictrl spi_mosi", false,-1);
        vcdp->declBit(c+881,"Endat_SPI_Ctrl spictrl spi_miso", false,-1);
        vcdp->declBit(c+1057,"Endat_SPI_Ctrl spictrl config_kind_cpol", false,-1);
        vcdp->declBit(c+1057,"Endat_SPI_Ctrl spictrl config_kind_cpha", false,-1);
        vcdp->declBus(c+1065,"Endat_SPI_Ctrl spictrl config_sclkToogle", false,-1, 7,0);
        vcdp->declBus(c+1057,"Endat_SPI_Ctrl spictrl config_ss_activeHigh", false,-1, 0,0);
        vcdp->declBus(c+1073,"Endat_SPI_Ctrl spictrl config_ss_setup", false,-1, 7,0);
        vcdp->declBus(c+1073,"Endat_SPI_Ctrl spictrl config_ss_hold", false,-1, 7,0);
        vcdp->declBus(c+1081,"Endat_SPI_Ctrl spictrl config_ss_disable", false,-1, 7,0);
        vcdp->declBit(c+553,"Endat_SPI_Ctrl spictrl cmd_valid", false,-1);
        vcdp->declBit(c+1,"Endat_SPI_Ctrl spictrl cmd_ready", false,-1);
        vcdp->declBus(c+673,"Endat_SPI_Ctrl spictrl cmd_payload", false,-1, 15,0);
        vcdp->declBit(c+9,"Endat_SPI_Ctrl spictrl rsp_valid", false,-1);
        vcdp->declBit(c+545,"Endat_SPI_Ctrl spictrl rsp_ready", false,-1);
        vcdp->declBus(c+497,"Endat_SPI_Ctrl spictrl rsp_payload", false,-1, 15,0);
        vcdp->declBus(c+17,"Endat_SPI_Ctrl spictrl occupancy", false,-1, 6,0);
        vcdp->declBit(c+993,"Endat_SPI_Ctrl spictrl clk", false,-1);
        vcdp->declBit(c+1001,"Endat_SPI_Ctrl spictrl reset", false,-1);
        vcdp->declBus(c+1009,"Endat_SPI_Ctrl spictrl fsm_enumDef_1_BOOT", false,-1, 2,0);
        vcdp->declBus(c+1017,"Endat_SPI_Ctrl spictrl fsm_enumDef_1_Init_Start", false,-1, 2,0);
        vcdp->declBus(c+1025,"Endat_SPI_Ctrl spictrl fsm_enumDef_1_Active_CS", false,-1, 2,0);
        vcdp->declBus(c+1033,"Endat_SPI_Ctrl spictrl fsm_enumDef_1_Send_Data", false,-1, 2,0);
        vcdp->declBus(c+1041,"Endat_SPI_Ctrl spictrl fsm_enumDef_1_Disable_CS", false,-1, 2,0);
        vcdp->declBus(c+1049,"Endat_SPI_Ctrl spictrl fsm_enumDef_1_Dummy_State", false,-1, 2,0);
        vcdp->declBit(c+1,"Endat_SPI_Ctrl spictrl wr_fifo_io_push_ready", false,-1);
        vcdp->declBit(c+105,"Endat_SPI_Ctrl spictrl wr_fifo_io_pop_valid", false,-1);
        vcdp->declBus(c+601,"Endat_SPI_Ctrl spictrl wr_fifo_io_pop_payload", false,-1, 15,0);
        vcdp->declBus(c+113,"Endat_SPI_Ctrl spictrl wr_fifo_io_occupancy", false,-1, 6,0);
        vcdp->declBus(c+121,"Endat_SPI_Ctrl spictrl wr_fifo_io_availability", false,-1, 6,0);
        vcdp->declBit(c+129,"Endat_SPI_Ctrl spictrl rd_fifo_io_push_ready", false,-1);
        vcdp->declBit(c+9,"Endat_SPI_Ctrl spictrl rd_fifo_io_pop_valid", false,-1);
        vcdp->declBus(c+497,"Endat_SPI_Ctrl spictrl rd_fifo_io_pop_payload", false,-1, 15,0);
        vcdp->declBus(c+17,"Endat_SPI_Ctrl spictrl rd_fifo_io_occupancy", false,-1, 6,0);
        vcdp->declBus(c+137,"Endat_SPI_Ctrl spictrl rd_fifo_io_availability", false,-1, 6,0);
        vcdp->declBus(c+825,"Endat_SPI_Ctrl spictrl timer_counter", false,-1, 7,0);
        vcdp->declBit(c+609,"Endat_SPI_Ctrl spictrl timer_reset", false,-1);
        vcdp->declBit(c+833,"Endat_SPI_Ctrl spictrl timer_ss_setupHit", false,-1);
        vcdp->declBit(c+833,"Endat_SPI_Ctrl spictrl timer_ss_holdHit", false,-1);
        vcdp->declBit(c+841,"Endat_SPI_Ctrl spictrl timer_ss_disableHit", false,-1);
        vcdp->declBit(c+849,"Endat_SPI_Ctrl spictrl timer_sclkToogleHit", false,-1);
        vcdp->declBit(c+617,"Endat_SPI_Ctrl spictrl wr_ready", false,-1);
        vcdp->declBit(c+1057,"Endat_SPI_Ctrl spictrl fsm_wantExit", false,-1);
        vcdp->declBit(c+145,"Endat_SPI_Ctrl spictrl fsm_wantStart", false,-1);
        vcdp->declBit(c+1057,"Endat_SPI_Ctrl spictrl fsm_wantKill", false,-1);
        vcdp->declBit(c+441,"Endat_SPI_Ctrl spictrl fsm_counter_willIncrement", false,-1);
        vcdp->declBit(c+1057,"Endat_SPI_Ctrl spictrl fsm_counter_willClear", false,-1);
        vcdp->declBus(c+377,"Endat_SPI_Ctrl spictrl fsm_counter_valueNext", false,-1, 4,0);
        vcdp->declBus(c+689,"Endat_SPI_Ctrl spictrl fsm_counter_value", false,-1, 4,0);
        vcdp->declBit(c+697,"Endat_SPI_Ctrl spictrl fsm_counter_willOverflowIfInc", false,-1);
        vcdp->declBit(c+385,"Endat_SPI_Ctrl spictrl fsm_counter_willOverflow", false,-1);
        vcdp->declBus(c+625,"Endat_SPI_Ctrl spictrl fsm_buffer", false,-1, 15,0);
        vcdp->declBus(c+705,"Endat_SPI_Ctrl spictrl fsm_ss", false,-1, 0,0);
        vcdp->declBus(c+633,"Endat_SPI_Ctrl spictrl fsm_wr_payload", false,-1, 15,0);
        vcdp->declBit(c+641,"Endat_SPI_Ctrl spictrl fsm_rsp_valid", false,-1);
        vcdp->declBus(c+713,"Endat_SPI_Ctrl spictrl fsm_stateReg", false,-1, 2,0);
        vcdp->declBus(c+449,"Endat_SPI_Ctrl spictrl fsm_stateNext", false,-1, 2,0);
        vcdp->declBit(c+153,"Endat_SPI_Ctrl spictrl when_Endat_SPI_Ctrl_l53", false,-1);
        vcdp->declBit(c+721,"Endat_SPI_Ctrl spictrl when_Endat_SPI_Ctrl_l76", false,-1);
        vcdp->declBit(c+697,"Endat_SPI_Ctrl spictrl when_Endat_SPI_Ctrl_l79", false,-1);
        vcdp->declArray(c+161,"Endat_SPI_Ctrl spictrl fsm_stateReg_string", false,-1, 87,0);
        vcdp->declArray(c+457,"Endat_SPI_Ctrl spictrl fsm_stateNext_string", false,-1, 87,0);
        vcdp->declBit(c+553,"Endat_SPI_Ctrl spictrl wr_fifo io_push_valid", false,-1);
        vcdp->declBit(c+1,"Endat_SPI_Ctrl spictrl wr_fifo io_push_ready", false,-1);
        vcdp->declBus(c+673,"Endat_SPI_Ctrl spictrl wr_fifo io_push_payload", false,-1, 15,0);
        vcdp->declBit(c+105,"Endat_SPI_Ctrl spictrl wr_fifo io_pop_valid", false,-1);
        vcdp->declBit(c+617,"Endat_SPI_Ctrl spictrl wr_fifo io_pop_ready", false,-1);
        vcdp->declBus(c+601,"Endat_SPI_Ctrl spictrl wr_fifo io_pop_payload", false,-1, 15,0);
        vcdp->declBit(c+1057,"Endat_SPI_Ctrl spictrl wr_fifo io_flush", false,-1);
        vcdp->declBus(c+113,"Endat_SPI_Ctrl spictrl wr_fifo io_occupancy", false,-1, 6,0);
        vcdp->declBus(c+121,"Endat_SPI_Ctrl spictrl wr_fifo io_availability", false,-1, 6,0);
        vcdp->declBit(c+993,"Endat_SPI_Ctrl spictrl wr_fifo clk", false,-1);
        vcdp->declBit(c+1001,"Endat_SPI_Ctrl spictrl wr_fifo reset", false,-1);
        vcdp->declBit(c+185,"Endat_SPI_Ctrl spictrl wr_fifo logic_pushPtr_willIncrement", false,-1);
        vcdp->declBit(c+1057,"Endat_SPI_Ctrl spictrl wr_fifo logic_pushPtr_willClear", false,-1);
        vcdp->declBus(c+193,"Endat_SPI_Ctrl spictrl wr_fifo logic_pushPtr_valueNext", false,-1, 5,0);
        vcdp->declBus(c+729,"Endat_SPI_Ctrl spictrl wr_fifo logic_pushPtr_value", false,-1, 5,0);
        vcdp->declBit(c+737,"Endat_SPI_Ctrl spictrl wr_fifo logic_pushPtr_willOverflowIfInc", false,-1);
        vcdp->declBit(c+201,"Endat_SPI_Ctrl spictrl wr_fifo logic_pushPtr_willOverflow", false,-1);
        vcdp->declBit(c+209,"Endat_SPI_Ctrl spictrl wr_fifo logic_popPtr_willIncrement", false,-1);
        vcdp->declBit(c+1057,"Endat_SPI_Ctrl spictrl wr_fifo logic_popPtr_willClear", false,-1);
        vcdp->declBus(c+217,"Endat_SPI_Ctrl spictrl wr_fifo logic_popPtr_valueNext", false,-1, 5,0);
        vcdp->declBus(c+745,"Endat_SPI_Ctrl spictrl wr_fifo logic_popPtr_value", false,-1, 5,0);
        vcdp->declBit(c+753,"Endat_SPI_Ctrl spictrl wr_fifo logic_popPtr_willOverflowIfInc", false,-1);
        vcdp->declBit(c+225,"Endat_SPI_Ctrl spictrl wr_fifo logic_popPtr_willOverflow", false,-1);
        vcdp->declBit(c+233,"Endat_SPI_Ctrl spictrl wr_fifo logic_ptrMatch", false,-1);
        vcdp->declBit(c+761,"Endat_SPI_Ctrl spictrl wr_fifo logic_risingOccupancy", false,-1);
        vcdp->declBit(c+241,"Endat_SPI_Ctrl spictrl wr_fifo logic_pushing", false,-1);
        vcdp->declBit(c+249,"Endat_SPI_Ctrl spictrl wr_fifo logic_popping", false,-1);
        vcdp->declBit(c+257,"Endat_SPI_Ctrl spictrl wr_fifo logic_empty", false,-1);
        vcdp->declBit(c+265,"Endat_SPI_Ctrl spictrl wr_fifo logic_full", false,-1);
        vcdp->declBit(c+273,"Endat_SPI_Ctrl spictrl wr_fifo when_Stream_l1101", false,-1);
        vcdp->declBus(c+769,"Endat_SPI_Ctrl spictrl wr_fifo logic_ptrDif", false,-1, 5,0);
        vcdp->declBit(c+641,"Endat_SPI_Ctrl spictrl rd_fifo io_push_valid", false,-1);
        vcdp->declBit(c+129,"Endat_SPI_Ctrl spictrl rd_fifo io_push_ready", false,-1);
        vcdp->declBus(c+625,"Endat_SPI_Ctrl spictrl rd_fifo io_push_payload", false,-1, 15,0);
        vcdp->declBit(c+9,"Endat_SPI_Ctrl spictrl rd_fifo io_pop_valid", false,-1);
        vcdp->declBit(c+545,"Endat_SPI_Ctrl spictrl rd_fifo io_pop_ready", false,-1);
        vcdp->declBus(c+497,"Endat_SPI_Ctrl spictrl rd_fifo io_pop_payload", false,-1, 15,0);
        vcdp->declBit(c+1057,"Endat_SPI_Ctrl spictrl rd_fifo io_flush", false,-1);
        vcdp->declBus(c+17,"Endat_SPI_Ctrl spictrl rd_fifo io_occupancy", false,-1, 6,0);
        vcdp->declBus(c+137,"Endat_SPI_Ctrl spictrl rd_fifo io_availability", false,-1, 6,0);
        vcdp->declBit(c+993,"Endat_SPI_Ctrl spictrl rd_fifo clk", false,-1);
        vcdp->declBit(c+1001,"Endat_SPI_Ctrl spictrl rd_fifo reset", false,-1);
        vcdp->declBit(c+281,"Endat_SPI_Ctrl spictrl rd_fifo logic_pushPtr_willIncrement", false,-1);
        vcdp->declBit(c+1057,"Endat_SPI_Ctrl spictrl rd_fifo logic_pushPtr_willClear", false,-1);
        vcdp->declBus(c+289,"Endat_SPI_Ctrl spictrl rd_fifo logic_pushPtr_valueNext", false,-1, 5,0);
        vcdp->declBus(c+777,"Endat_SPI_Ctrl spictrl rd_fifo logic_pushPtr_value", false,-1, 5,0);
        vcdp->declBit(c+785,"Endat_SPI_Ctrl spictrl rd_fifo logic_pushPtr_willOverflowIfInc", false,-1);
        vcdp->declBit(c+297,"Endat_SPI_Ctrl spictrl rd_fifo logic_pushPtr_willOverflow", false,-1);
        vcdp->declBit(c+305,"Endat_SPI_Ctrl spictrl rd_fifo logic_popPtr_willIncrement", false,-1);
        vcdp->declBit(c+1057,"Endat_SPI_Ctrl spictrl rd_fifo logic_popPtr_willClear", false,-1);
        vcdp->declBus(c+313,"Endat_SPI_Ctrl spictrl rd_fifo logic_popPtr_valueNext", false,-1, 5,0);
        vcdp->declBus(c+793,"Endat_SPI_Ctrl spictrl rd_fifo logic_popPtr_value", false,-1, 5,0);
        vcdp->declBit(c+801,"Endat_SPI_Ctrl spictrl rd_fifo logic_popPtr_willOverflowIfInc", false,-1);
        vcdp->declBit(c+321,"Endat_SPI_Ctrl spictrl rd_fifo logic_popPtr_willOverflow", false,-1);
        vcdp->declBit(c+329,"Endat_SPI_Ctrl spictrl rd_fifo logic_ptrMatch", false,-1);
        vcdp->declBit(c+809,"Endat_SPI_Ctrl spictrl rd_fifo logic_risingOccupancy", false,-1);
        vcdp->declBit(c+337,"Endat_SPI_Ctrl spictrl rd_fifo logic_pushing", false,-1);
        vcdp->declBit(c+345,"Endat_SPI_Ctrl spictrl rd_fifo logic_popping", false,-1);
        vcdp->declBit(c+353,"Endat_SPI_Ctrl spictrl rd_fifo logic_empty", false,-1);
        vcdp->declBit(c+361,"Endat_SPI_Ctrl spictrl rd_fifo logic_full", false,-1);
        vcdp->declBit(c+369,"Endat_SPI_Ctrl spictrl rd_fifo when_Stream_l1101", false,-1);
        vcdp->declBus(c+817,"Endat_SPI_Ctrl spictrl rd_fifo logic_ptrDif", false,-1, 5,0);
    }
}

void VEndat_SPI_Ctrl::traceFullThis__1(VEndat_SPI_Ctrl__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VEndat_SPI_Ctrl* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->fullBit(c+1,((1U & (~ (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_full)))));
        vcdp->fullBit(c+9,(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo_io_pop_valid));
        vcdp->fullBus(c+17,(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo_io_occupancy),7);
        vcdp->fullBit(c+25,(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_wantStart));
        vcdp->fullBit(c+33,(vlTOPp->Endat_SPI_Ctrl__DOT__when_Endat_SPI_Ctrl_l183));
        vcdp->fullBit(c+41,(vlTOPp->Endat_SPI_Ctrl__DOT__when_Endat_SPI_Ctrl_l196));
        vcdp->fullBit(c+49,(vlTOPp->Endat_SPI_Ctrl__DOT__when_Endat_SPI_Ctrl_l204));
        vcdp->fullBit(c+57,((0U != (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo_io_occupancy))));
        vcdp->fullArray(c+65,(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_stateReg_string),144);
        vcdp->fullBit(c+105,((1U & ((~ ((IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_ptrMatch) 
                                        & (~ (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_risingOccupancy)))) 
                                    & (~ ((IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT___zz_io_pop_valid) 
                                          & (~ (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_full))))))));
        vcdp->fullBus(c+113,(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo_io_occupancy),7);
        vcdp->fullBus(c+121,(((((~ (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_risingOccupancy)) 
                                & (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_ptrMatch)) 
                               << 6U) | (0x3fU & ((IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_popPtr_value) 
                                                  - (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_pushPtr_value))))),7);
        vcdp->fullBit(c+129,((1U & (~ (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_full)))));
        vcdp->fullBus(c+137,(((((~ (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_risingOccupancy)) 
                                & (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_ptrMatch)) 
                               << 6U) | (0x3fU & ((IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_popPtr_value) 
                                                  - (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_pushPtr_value))))),7);
        vcdp->fullBit(c+145,(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_wantStart));
        vcdp->fullBit(c+153,((0U != (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo_io_occupancy))));
        vcdp->fullArray(c+161,(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_stateReg_string),88);
        vcdp->fullBit(c+185,(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_pushPtr_willIncrement));
        vcdp->fullBus(c+193,(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_pushPtr_valueNext),6);
        vcdp->fullBit(c+201,(((0x3fU == (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_pushPtr_value)) 
                              & (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_pushPtr_willIncrement))));
        vcdp->fullBit(c+209,(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_popPtr_willIncrement));
        vcdp->fullBus(c+217,(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_popPtr_valueNext),6);
        vcdp->fullBit(c+225,(((0x3fU == (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_popPtr_value)) 
                              & (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_popPtr_willIncrement))));
        vcdp->fullBit(c+233,(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_ptrMatch));
        vcdp->fullBit(c+241,(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_pushing));
        vcdp->fullBit(c+249,(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_popping));
        vcdp->fullBit(c+257,(((IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_ptrMatch) 
                              & (~ (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_risingOccupancy)))));
        vcdp->fullBit(c+265,(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_full));
        vcdp->fullBit(c+273,(((IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_pushing) 
                              != (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_popping))));
        vcdp->fullBit(c+281,(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_pushPtr_willIncrement));
        vcdp->fullBus(c+289,(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_pushPtr_valueNext),6);
        vcdp->fullBit(c+297,(((0x3fU == (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_pushPtr_value)) 
                              & (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_pushPtr_willIncrement))));
        vcdp->fullBit(c+305,(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_popPtr_willIncrement));
        vcdp->fullBus(c+313,(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_popPtr_valueNext),6);
        vcdp->fullBit(c+321,(((0x3fU == (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_popPtr_value)) 
                              & (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_popPtr_willIncrement))));
        vcdp->fullBit(c+329,(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_ptrMatch));
        vcdp->fullBit(c+337,(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_pushing));
        vcdp->fullBit(c+345,(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_popping));
        vcdp->fullBit(c+353,(((IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_ptrMatch) 
                              & (~ (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_risingOccupancy)))));
        vcdp->fullBit(c+361,(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_full));
        vcdp->fullBit(c+369,(((IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_pushing) 
                              != (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_popping))));
        vcdp->fullBus(c+377,((0x1fU & ((IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_counter_value) 
                                       + (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_counter_willIncrement)))),5);
        vcdp->fullBit(c+385,(((0x1fU == (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_counter_value)) 
                              & (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_counter_willIncrement))));
        vcdp->fullBus(c+393,(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_stateNext),3);
        vcdp->fullArray(c+401,(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_stateNext_string),144);
        vcdp->fullBit(c+441,(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_counter_willIncrement));
        vcdp->fullBus(c+449,(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_stateNext),3);
        vcdp->fullArray(c+457,(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_stateNext_string),88);
        vcdp->fullBit(c+481,(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT___zz_spi_sclk));
        vcdp->fullBit(c+489,(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT___zz_spi_mosi));
        vcdp->fullBus(c+497,(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT___zz_logic_ram_port0),16);
        vcdp->fullBus(c+505,(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_CmdData_0),16);
        vcdp->fullBus(c+513,(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_CmdData_1),16);
        vcdp->fullBus(c+521,(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_CmdData_2),16);
        vcdp->fullBus(c+529,(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_CmdData_3),16);
        vcdp->fullBus(c+537,(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_Cycle),2);
        vcdp->fullBit(c+545,(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_rdfifo_ready));
        vcdp->fullBit(c+553,(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_spi_cmd_valid));
        vcdp->fullBus(c+561,(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_rspData_0),16);
        vcdp->fullBus(c+569,(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_rspData_1),16);
        vcdp->fullBus(c+577,(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_rspData_2),16);
        vcdp->fullBus(c+585,(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_rspData_3),16);
        vcdp->fullBus(c+593,(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_rspData_4),16);
        vcdp->fullBus(c+601,(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT___zz_logic_ram_port0),16);
        vcdp->fullBit(c+609,(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__timer_reset));
        vcdp->fullBit(c+617,(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_ready));
        vcdp->fullBus(c+625,(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_buffer),16);
        vcdp->fullBus(c+633,(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_wr_payload),16);
        vcdp->fullBit(c+641,(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_rsp_valid));
        vcdp->fullBit(c+649,(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_ss));
        vcdp->fullBus(c+657,(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_Identity_Addr),16);
        vcdp->fullBus(c+665,(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_counter),4);
        vcdp->fullBus(c+673,(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_spi_cmd_payload),16);
        vcdp->fullBus(c+681,(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_stateReg),3);
        vcdp->fullBus(c+689,(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_counter_value),5);
        vcdp->fullBit(c+697,((0x1fU == (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_counter_value))));
        vcdp->fullBit(c+705,(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_ss));
        vcdp->fullBus(c+713,(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_stateReg),3);
        vcdp->fullBit(c+721,((1U & (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_counter_value))));
        vcdp->fullBus(c+729,(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_pushPtr_value),6);
        vcdp->fullBit(c+737,((0x3fU == (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_pushPtr_value))));
        vcdp->fullBus(c+745,(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_popPtr_value),6);
        vcdp->fullBit(c+753,((0x3fU == (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_popPtr_value))));
        vcdp->fullBit(c+761,(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_risingOccupancy));
        vcdp->fullBus(c+769,((0x3fU & ((IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_pushPtr_value) 
                                       - (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_popPtr_value)))),6);
        vcdp->fullBus(c+777,(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_pushPtr_value),6);
        vcdp->fullBit(c+785,((0x3fU == (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_pushPtr_value))));
        vcdp->fullBus(c+793,(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_popPtr_value),6);
        vcdp->fullBit(c+801,((0x3fU == (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_popPtr_value))));
        vcdp->fullBit(c+809,(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_risingOccupancy));
        vcdp->fullBus(c+817,((0x3fU & ((IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_pushPtr_value) 
                                       - (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_popPtr_value)))),6);
        vcdp->fullBus(c+825,(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__timer_counter),8);
        vcdp->fullBit(c+833,((0x64U == (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__timer_counter))));
        vcdp->fullBit(c+841,((0xc8U == (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__timer_counter))));
        vcdp->fullBit(c+849,((0xaU == (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__timer_counter))));
        vcdp->fullBit(c+857,(vlTOPp->spi_ss));
        vcdp->fullBit(c+865,(vlTOPp->spi_sclk));
        vcdp->fullBit(c+873,(vlTOPp->spi_mosi));
        vcdp->fullBit(c+881,(vlTOPp->spi_miso));
        vcdp->fullBit(c+889,(vlTOPp->cmddata_valid));
        vcdp->fullBus(c+897,(vlTOPp->cmddata_payload_Identity_Addr),16);
        vcdp->fullBus(c+905,(vlTOPp->cmddata_payload_CmdData_0),16);
        vcdp->fullBus(c+913,(vlTOPp->cmddata_payload_CmdData_1),16);
        vcdp->fullBus(c+921,(vlTOPp->cmddata_payload_CmdData_2),16);
        vcdp->fullBus(c+929,(vlTOPp->cmddata_payload_CmdData_3),16);
        vcdp->fullBus(c+937,(vlTOPp->cmddata_payload_Bytenumber),6);
        vcdp->fullBit(c+945,(vlTOPp->rspdata_valid));
        vcdp->fullBus(c+953,(vlTOPp->rspdata_payload_RspData_0),16);
        vcdp->fullBus(c+961,(vlTOPp->rspdata_payload_RspData_1),16);
        vcdp->fullBus(c+969,(vlTOPp->rspdata_payload_RspData_2),16);
        vcdp->fullBus(c+977,(vlTOPp->rspdata_payload_RspData_3),16);
        vcdp->fullBus(c+985,(vlTOPp->rspdata_payload_RspData_4),16);
        vcdp->fullBit(c+993,(vlTOPp->clk));
        vcdp->fullBit(c+1001,(vlTOPp->reset));
        vcdp->fullBus(c+1009,(0U),3);
        vcdp->fullBus(c+1017,(1U),3);
        vcdp->fullBus(c+1025,(2U),3);
        vcdp->fullBus(c+1033,(3U),3);
        vcdp->fullBus(c+1041,(4U),3);
        vcdp->fullBus(c+1049,(5U),3);
        vcdp->fullBit(c+1057,(0U));
        vcdp->fullBus(c+1065,(0xaU),8);
        vcdp->fullBus(c+1073,(0x64U),8);
        vcdp->fullBus(c+1081,(0xc8U),8);
    }
}
