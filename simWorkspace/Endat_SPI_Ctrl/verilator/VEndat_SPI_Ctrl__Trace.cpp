// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VEndat_SPI_Ctrl__Syms.h"


//======================

void VEndat_SPI_Ctrl::traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    VEndat_SPI_Ctrl* t = (VEndat_SPI_Ctrl*)userthis;
    VEndat_SPI_Ctrl__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (vlSymsp->getClearActivity()) {
        t->traceChgThis(vlSymsp, vcdp, code);
    }
}

//======================


void VEndat_SPI_Ctrl::traceChgThis(VEndat_SPI_Ctrl__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VEndat_SPI_Ctrl* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
                               | (vlTOPp->__Vm_traceActivity 
                                  >> 2U))))) {
            vlTOPp->traceChgThis__2(vlSymsp, vcdp, code);
        }
        if (VL_UNLIKELY((1U & ((vlTOPp->__Vm_traceActivity 
                                | (vlTOPp->__Vm_traceActivity 
                                   >> 2U)) | (vlTOPp->__Vm_traceActivity 
                                              >> 5U))))) {
            vlTOPp->traceChgThis__3(vlSymsp, vcdp, code);
        }
        if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
                               | (vlTOPp->__Vm_traceActivity 
                                  >> 3U))))) {
            vlTOPp->traceChgThis__4(vlSymsp, vcdp, code);
        }
        if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
                               | (vlTOPp->__Vm_traceActivity 
                                  >> 5U))))) {
            vlTOPp->traceChgThis__5(vlSymsp, vcdp, code);
        }
        if (VL_UNLIKELY((2U & vlTOPp->__Vm_traceActivity))) {
            vlTOPp->traceChgThis__6(vlSymsp, vcdp, code);
        }
        if (VL_UNLIKELY((4U & vlTOPp->__Vm_traceActivity))) {
            vlTOPp->traceChgThis__7(vlSymsp, vcdp, code);
        }
        if (VL_UNLIKELY((0x10U & vlTOPp->__Vm_traceActivity))) {
            vlTOPp->traceChgThis__8(vlSymsp, vcdp, code);
        }
        vlTOPp->traceChgThis__9(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void VEndat_SPI_Ctrl::traceChgThis__2(VEndat_SPI_Ctrl__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VEndat_SPI_Ctrl* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(c+1,((1U & (~ (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_full)))));
        vcdp->chgBit(c+9,(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo_io_pop_valid));
        vcdp->chgBus(c+17,(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo_io_occupancy),7);
        vcdp->chgBit(c+25,(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_wantStart));
        vcdp->chgBit(c+33,(vlTOPp->Endat_SPI_Ctrl__DOT__when_Endat_SPI_Ctrl_l183));
        vcdp->chgBit(c+41,(vlTOPp->Endat_SPI_Ctrl__DOT__when_Endat_SPI_Ctrl_l196));
        vcdp->chgBit(c+49,(vlTOPp->Endat_SPI_Ctrl__DOT__when_Endat_SPI_Ctrl_l204));
        vcdp->chgBit(c+57,((0U != (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo_io_occupancy))));
        vcdp->chgArray(c+65,(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_stateReg_string),144);
        vcdp->chgBit(c+105,((1U & ((~ ((IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_ptrMatch) 
                                       & (~ (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_risingOccupancy)))) 
                                   & (~ ((IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT___zz_io_pop_valid) 
                                         & (~ (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_full))))))));
        vcdp->chgBus(c+113,(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo_io_occupancy),7);
        vcdp->chgBus(c+121,(((((~ (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_risingOccupancy)) 
                               & (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_ptrMatch)) 
                              << 6U) | (0x3fU & ((IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_popPtr_value) 
                                                 - (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_pushPtr_value))))),7);
        vcdp->chgBit(c+129,((1U & (~ (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_full)))));
        vcdp->chgBus(c+137,(((((~ (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_risingOccupancy)) 
                               & (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_ptrMatch)) 
                              << 6U) | (0x3fU & ((IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_popPtr_value) 
                                                 - (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_pushPtr_value))))),7);
        vcdp->chgBit(c+145,(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_wantStart));
        vcdp->chgBit(c+153,((0U != (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo_io_occupancy))));
        vcdp->chgArray(c+161,(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_stateReg_string),88);
        vcdp->chgBit(c+185,(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_pushPtr_willIncrement));
        vcdp->chgBus(c+193,(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_pushPtr_valueNext),6);
        vcdp->chgBit(c+201,(((0x3fU == (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_pushPtr_value)) 
                             & (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_pushPtr_willIncrement))));
        vcdp->chgBit(c+209,(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_popPtr_willIncrement));
        vcdp->chgBus(c+217,(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_popPtr_valueNext),6);
        vcdp->chgBit(c+225,(((0x3fU == (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_popPtr_value)) 
                             & (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_popPtr_willIncrement))));
        vcdp->chgBit(c+233,(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_ptrMatch));
        vcdp->chgBit(c+241,(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_pushing));
        vcdp->chgBit(c+249,(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_popping));
        vcdp->chgBit(c+257,(((IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_ptrMatch) 
                             & (~ (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_risingOccupancy)))));
        vcdp->chgBit(c+265,(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_full));
        vcdp->chgBit(c+273,(((IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_pushing) 
                             != (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_popping))));
        vcdp->chgBit(c+281,(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_pushPtr_willIncrement));
        vcdp->chgBus(c+289,(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_pushPtr_valueNext),6);
        vcdp->chgBit(c+297,(((0x3fU == (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_pushPtr_value)) 
                             & (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_pushPtr_willIncrement))));
        vcdp->chgBit(c+305,(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_popPtr_willIncrement));
        vcdp->chgBus(c+313,(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_popPtr_valueNext),6);
        vcdp->chgBit(c+321,(((0x3fU == (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_popPtr_value)) 
                             & (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_popPtr_willIncrement))));
        vcdp->chgBit(c+329,(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_ptrMatch));
        vcdp->chgBit(c+337,(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_pushing));
        vcdp->chgBit(c+345,(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_popping));
        vcdp->chgBit(c+353,(((IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_ptrMatch) 
                             & (~ (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_risingOccupancy)))));
        vcdp->chgBit(c+361,(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_full));
        vcdp->chgBit(c+369,(((IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_pushing) 
                             != (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_popping))));
    }
}

void VEndat_SPI_Ctrl::traceChgThis__3(VEndat_SPI_Ctrl__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VEndat_SPI_Ctrl* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBus(c+377,((0x1fU & ((IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_counter_value) 
                                      + (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_counter_willIncrement)))),5);
        vcdp->chgBit(c+385,(((0x1fU == (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_counter_value)) 
                             & (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_counter_willIncrement))));
    }
}

void VEndat_SPI_Ctrl::traceChgThis__4(VEndat_SPI_Ctrl__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VEndat_SPI_Ctrl* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBus(c+393,(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_stateNext),3);
        vcdp->chgArray(c+401,(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_stateNext_string),144);
    }
}

void VEndat_SPI_Ctrl::traceChgThis__5(VEndat_SPI_Ctrl__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VEndat_SPI_Ctrl* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(c+441,(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_counter_willIncrement));
        vcdp->chgBus(c+449,(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_stateNext),3);
        vcdp->chgArray(c+457,(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_stateNext_string),88);
    }
}

void VEndat_SPI_Ctrl::traceChgThis__6(VEndat_SPI_Ctrl__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VEndat_SPI_Ctrl* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(c+481,(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT___zz_spi_sclk));
        vcdp->chgBit(c+489,(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT___zz_spi_mosi));
        vcdp->chgBus(c+497,(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT___zz_logic_ram_port0),16);
        vcdp->chgBus(c+505,(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_CmdData_0),16);
        vcdp->chgBus(c+513,(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_CmdData_1),16);
        vcdp->chgBus(c+521,(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_CmdData_2),16);
        vcdp->chgBus(c+529,(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_CmdData_3),16);
        vcdp->chgBus(c+537,(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_Cycle),2);
        vcdp->chgBit(c+545,(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_rdfifo_ready));
        vcdp->chgBit(c+553,(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_spi_cmd_valid));
        vcdp->chgBus(c+561,(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_rspData_0),16);
        vcdp->chgBus(c+569,(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_rspData_1),16);
        vcdp->chgBus(c+577,(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_rspData_2),16);
        vcdp->chgBus(c+585,(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_rspData_3),16);
        vcdp->chgBus(c+593,(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_rspData_4),16);
        vcdp->chgBus(c+601,(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT___zz_logic_ram_port0),16);
        vcdp->chgBit(c+609,(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__timer_reset));
        vcdp->chgBit(c+617,(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_ready));
        vcdp->chgBus(c+625,(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_buffer),16);
        vcdp->chgBus(c+633,(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_wr_payload),16);
        vcdp->chgBit(c+641,(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_rsp_valid));
    }
}

void VEndat_SPI_Ctrl::traceChgThis__7(VEndat_SPI_Ctrl__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VEndat_SPI_Ctrl* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(c+649,(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_ss));
        vcdp->chgBus(c+657,(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_Identity_Addr),16);
        vcdp->chgBus(c+665,(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_counter),4);
        vcdp->chgBus(c+673,(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_spi_cmd_payload),16);
        vcdp->chgBus(c+681,(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_stateReg),3);
        vcdp->chgBus(c+689,(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_counter_value),5);
        vcdp->chgBit(c+697,((0x1fU == (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_counter_value))));
        vcdp->chgBit(c+705,(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_ss));
        vcdp->chgBus(c+713,(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_stateReg),3);
        vcdp->chgBit(c+721,((1U & (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_counter_value))));
        vcdp->chgBus(c+729,(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_pushPtr_value),6);
        vcdp->chgBit(c+737,((0x3fU == (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_pushPtr_value))));
        vcdp->chgBus(c+745,(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_popPtr_value),6);
        vcdp->chgBit(c+753,((0x3fU == (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_popPtr_value))));
        vcdp->chgBit(c+761,(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_risingOccupancy));
        vcdp->chgBus(c+769,((0x3fU & ((IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_pushPtr_value) 
                                      - (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_popPtr_value)))),6);
        vcdp->chgBus(c+777,(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_pushPtr_value),6);
        vcdp->chgBit(c+785,((0x3fU == (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_pushPtr_value))));
        vcdp->chgBus(c+793,(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_popPtr_value),6);
        vcdp->chgBit(c+801,((0x3fU == (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_popPtr_value))));
        vcdp->chgBit(c+809,(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_risingOccupancy));
        vcdp->chgBus(c+817,((0x3fU & ((IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_pushPtr_value) 
                                      - (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_popPtr_value)))),6);
    }
}

void VEndat_SPI_Ctrl::traceChgThis__8(VEndat_SPI_Ctrl__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VEndat_SPI_Ctrl* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBus(c+825,(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__timer_counter),8);
        vcdp->chgBit(c+833,((0x64U == (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__timer_counter))));
        vcdp->chgBit(c+841,((0xc8U == (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__timer_counter))));
        vcdp->chgBit(c+849,((0xaU == (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__timer_counter))));
    }
}

void VEndat_SPI_Ctrl::traceChgThis__9(VEndat_SPI_Ctrl__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VEndat_SPI_Ctrl* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(c+857,(vlTOPp->spi_ss));
        vcdp->chgBit(c+865,(vlTOPp->spi_sclk));
        vcdp->chgBit(c+873,(vlTOPp->spi_mosi));
        vcdp->chgBit(c+881,(vlTOPp->spi_miso));
        vcdp->chgBit(c+889,(vlTOPp->cmddata_valid));
        vcdp->chgBus(c+897,(vlTOPp->cmddata_payload_Identity_Addr),16);
        vcdp->chgBus(c+905,(vlTOPp->cmddata_payload_CmdData_0),16);
        vcdp->chgBus(c+913,(vlTOPp->cmddata_payload_CmdData_1),16);
        vcdp->chgBus(c+921,(vlTOPp->cmddata_payload_CmdData_2),16);
        vcdp->chgBus(c+929,(vlTOPp->cmddata_payload_CmdData_3),16);
        vcdp->chgBus(c+937,(vlTOPp->cmddata_payload_Bytenumber),6);
        vcdp->chgBit(c+945,(vlTOPp->rspdata_valid));
        vcdp->chgBus(c+953,(vlTOPp->rspdata_payload_RspData_0),16);
        vcdp->chgBus(c+961,(vlTOPp->rspdata_payload_RspData_1),16);
        vcdp->chgBus(c+969,(vlTOPp->rspdata_payload_RspData_2),16);
        vcdp->chgBus(c+977,(vlTOPp->rspdata_payload_RspData_3),16);
        vcdp->chgBus(c+985,(vlTOPp->rspdata_payload_RspData_4),16);
        vcdp->chgBit(c+993,(vlTOPp->clk));
        vcdp->chgBit(c+1001,(vlTOPp->reset));
    }
}
