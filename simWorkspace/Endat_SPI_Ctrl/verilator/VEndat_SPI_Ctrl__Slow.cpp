// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VEndat_SPI_Ctrl.h for the primary calling header

#include "VEndat_SPI_Ctrl.h"
#include "VEndat_SPI_Ctrl__Syms.h"

//==========
WData/*143:0*/ VEndat_SPI_Ctrl::__Vtable1_Endat_SPI_Ctrl__DOT__fsm_stateReg_string[8][5];
WData/*143:0*/ VEndat_SPI_Ctrl::__Vtable2_Endat_SPI_Ctrl__DOT__fsm_stateNext_string[8][5];
CData/*0:0*/ VEndat_SPI_Ctrl::__Vtable3_Endat_SPI_Ctrl__DOT__fsm_wantStart[8];
CData/*2:0*/ VEndat_SPI_Ctrl::__Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[256];
WData/*87:0*/ VEndat_SPI_Ctrl::__Vtable5_Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_stateReg_string[8][3];
WData/*87:0*/ VEndat_SPI_Ctrl::__Vtable6_Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_stateNext_string[8][3];
CData/*0:0*/ VEndat_SPI_Ctrl::__Vtable7_Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_wantStart[8];
CData/*0:0*/ VEndat_SPI_Ctrl::__Vtable8_Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_counter_willIncrement[16];

VL_CTOR_IMP(VEndat_SPI_Ctrl) {
    VEndat_SPI_Ctrl__Syms* __restrict vlSymsp = __VlSymsp = new VEndat_SPI_Ctrl__Syms(this, name());
    VEndat_SPI_Ctrl* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void VEndat_SPI_Ctrl::__Vconfigure(VEndat_SPI_Ctrl__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

VEndat_SPI_Ctrl::~VEndat_SPI_Ctrl() {
    delete __VlSymsp; __VlSymsp=NULL;
}

void VEndat_SPI_Ctrl::_settle__TOP__6(VEndat_SPI_Ctrl__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VEndat_SPI_Ctrl::_settle__TOP__6\n"); );
    VEndat_SPI_Ctrl* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->spi_sclk = vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT___zz_spi_sclk;
    vlTOPp->spi_mosi = vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT___zz_spi_mosi;
    vlTOPp->rspdata_payload_RspData_0 = vlTOPp->Endat_SPI_Ctrl__DOT__fsm_rspData_0;
    vlTOPp->rspdata_payload_RspData_1 = vlTOPp->Endat_SPI_Ctrl__DOT__fsm_rspData_1;
    vlTOPp->rspdata_payload_RspData_2 = vlTOPp->Endat_SPI_Ctrl__DOT__fsm_rspData_2;
    vlTOPp->rspdata_payload_RspData_3 = vlTOPp->Endat_SPI_Ctrl__DOT__fsm_rspData_3;
    vlTOPp->rspdata_payload_RspData_4 = vlTOPp->Endat_SPI_Ctrl__DOT__fsm_rspData_4;
    vlTOPp->Endat_SPI_Ctrl__DOT__when_Endat_SPI_Ctrl_l204 
        = ((IData)(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_counter) 
           < (3U & ((IData)(1U) + (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_Cycle))));
    vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT___zz_fsm_buffer 
        = (((IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_buffer) 
            << 1U) | (IData)(vlTOPp->spi_miso));
    vlTOPp->Endat_SPI_Ctrl__DOT___zz_fsm_spi_cmd_payload 
        = ((0U == (3U & (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_counter)))
            ? (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_CmdData_0)
            : ((1U == (3U & (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_counter)))
                ? (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_CmdData_1)
                : ((2U == (3U & (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_counter)))
                    ? (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_CmdData_2)
                    : (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_CmdData_3))));
    vlTOPp->Endat_SPI_Ctrl__DOT__when_Endat_SPI_Ctrl_l183 
        = ((IData)(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_counter) 
           < (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_Cycle));
    vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_ptrMatch 
        = ((IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_pushPtr_value) 
           == (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_popPtr_value));
    vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_ptrMatch 
        = ((IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_pushPtr_value) 
           == (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_popPtr_value));
    vlTOPp->spi_ss = vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_ss;
    vlTOPp->__Vtableidx1 = vlTOPp->Endat_SPI_Ctrl__DOT__fsm_stateReg;
    vlTOPp->Endat_SPI_Ctrl__DOT__fsm_stateReg_string[0U] 
        = vlTOPp->__Vtable1_Endat_SPI_Ctrl__DOT__fsm_stateReg_string
        [vlTOPp->__Vtableidx1][0U];
    vlTOPp->Endat_SPI_Ctrl__DOT__fsm_stateReg_string[1U] 
        = vlTOPp->__Vtable1_Endat_SPI_Ctrl__DOT__fsm_stateReg_string
        [vlTOPp->__Vtableidx1][1U];
    vlTOPp->Endat_SPI_Ctrl__DOT__fsm_stateReg_string[2U] 
        = vlTOPp->__Vtable1_Endat_SPI_Ctrl__DOT__fsm_stateReg_string
        [vlTOPp->__Vtableidx1][2U];
    vlTOPp->Endat_SPI_Ctrl__DOT__fsm_stateReg_string[3U] 
        = vlTOPp->__Vtable1_Endat_SPI_Ctrl__DOT__fsm_stateReg_string
        [vlTOPp->__Vtableidx1][3U];
    vlTOPp->Endat_SPI_Ctrl__DOT__fsm_stateReg_string[4U] 
        = vlTOPp->__Vtable1_Endat_SPI_Ctrl__DOT__fsm_stateReg_string
        [vlTOPp->__Vtableidx1][4U];
    vlTOPp->__Vtableidx3 = vlTOPp->Endat_SPI_Ctrl__DOT__fsm_stateReg;
    vlTOPp->Endat_SPI_Ctrl__DOT__fsm_wantStart = vlTOPp->__Vtable3_Endat_SPI_Ctrl__DOT__fsm_wantStart
        [vlTOPp->__Vtableidx3];
    vlTOPp->__Vtableidx5 = vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_stateReg;
    vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_stateReg_string[0U] 
        = vlTOPp->__Vtable5_Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_stateReg_string
        [vlTOPp->__Vtableidx5][0U];
    vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_stateReg_string[1U] 
        = vlTOPp->__Vtable5_Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_stateReg_string
        [vlTOPp->__Vtableidx5][1U];
    vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_stateReg_string[2U] 
        = vlTOPp->__Vtable5_Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_stateReg_string
        [vlTOPp->__Vtableidx5][2U];
    vlTOPp->__Vtableidx8 = (((0xaU == (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__timer_counter)) 
                             << 3U) | (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_stateReg));
    vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_counter_willIncrement 
        = vlTOPp->__Vtable8_Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_counter_willIncrement
        [vlTOPp->__Vtableidx8];
    vlTOPp->__Vtableidx7 = vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_stateReg;
    vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_wantStart 
        = vlTOPp->__Vtable7_Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_wantStart
        [vlTOPp->__Vtableidx7];
    vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo_io_occupancy 
        = ((((IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_risingOccupancy) 
             & (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_ptrMatch)) 
            << 6U) | (0x3fU & ((IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_pushPtr_value) 
                               - (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_popPtr_value))));
    vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_full 
        = ((IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_ptrMatch) 
           & (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_risingOccupancy));
    vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo_io_occupancy 
        = ((((IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_risingOccupancy) 
             & (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_ptrMatch)) 
            << 6U) | (0x3fU & ((IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_pushPtr_value) 
                               - (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_popPtr_value))));
    vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_full 
        = ((IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_ptrMatch) 
           & (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_risingOccupancy));
    vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_counter_valueNext 
        = (0x1fU & ((IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_counter_value) 
                    + (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_counter_willIncrement)));
    vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_stateNext 
        = vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_stateReg;
    if ((4U & (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_stateReg))) {
        if ((1U & (~ ((IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_stateReg) 
                      >> 1U)))) {
            if ((1U & (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_stateReg))) {
                if ((0xc8U == (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__timer_counter))) {
                    vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_stateNext = 1U;
                }
            } else {
                if ((0x64U == (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__timer_counter))) {
                    vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_stateNext = 5U;
                }
            }
        }
    } else {
        if ((2U & (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_stateReg))) {
            if ((1U & (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_stateReg))) {
                if ((0xaU == (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__timer_counter))) {
                    if ((0x1fU == (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_counter_value))) {
                        vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_stateNext = 4U;
                    }
                }
            } else {
                if ((0x64U == (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__timer_counter))) {
                    vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_stateNext = 3U;
                }
            }
        } else {
            if ((1U & (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_stateReg))) {
                if ((0U != (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo_io_occupancy))) {
                    vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_stateNext = 2U;
                }
            }
        }
    }
    if (vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_wantStart) {
        vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_stateNext = 1U;
    }
    vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_popping 
        = (((~ ((IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_ptrMatch) 
                & (~ (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_risingOccupancy)))) 
            & (~ ((IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT___zz_io_pop_valid) 
                  & (~ (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_full))))) 
           & (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_ready));
    vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_pushing 
        = ((IData)(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_spi_cmd_valid) 
           & (~ (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_full)));
    vlTOPp->Endat_SPI_Ctrl__DOT__when_Endat_SPI_Ctrl_l196 
        = ((3U & ((IData)(1U) + (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_Cycle))) 
           <= (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo_io_occupancy));
    vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_pushing 
        = ((IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_rsp_valid) 
           & (~ (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_full)));
    vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo_io_pop_valid 
        = (1U & ((~ ((IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_ptrMatch) 
                     & (~ (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_risingOccupancy)))) 
                 & (~ ((IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT___zz_io_pop_valid) 
                       & (~ (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_full))))));
    vlTOPp->__Vtableidx6 = vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_stateNext;
    vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_stateNext_string[0U] 
        = vlTOPp->__Vtable6_Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_stateNext_string
        [vlTOPp->__Vtableidx6][0U];
    vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_stateNext_string[1U] 
        = vlTOPp->__Vtable6_Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_stateNext_string
        [vlTOPp->__Vtableidx6][1U];
    vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_stateNext_string[2U] 
        = vlTOPp->__Vtable6_Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_stateNext_string
        [vlTOPp->__Vtableidx6][2U];
    vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_popPtr_willIncrement = 0U;
    if (vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_popping) {
        vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_popPtr_willIncrement = 1U;
    }
    vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT___zz_1 = 0U;
    if (vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_pushing) {
        vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT___zz_1 = 1U;
    }
    vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_pushPtr_willIncrement = 0U;
    if (vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_pushing) {
        vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_pushPtr_willIncrement = 1U;
    }
    vlTOPp->__Vtableidx4 = (((IData)(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_wantStart) 
                             << 7U) | (((IData)(vlTOPp->cmddata_valid) 
                                        << 6U) | (((IData)(vlTOPp->Endat_SPI_Ctrl__DOT__when_Endat_SPI_Ctrl_l183) 
                                                   << 5U) 
                                                  | (((IData)(vlTOPp->Endat_SPI_Ctrl__DOT__when_Endat_SPI_Ctrl_l196) 
                                                      << 4U) 
                                                     | (((0U 
                                                          != (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo_io_occupancy)) 
                                                         << 3U) 
                                                        | (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_stateReg))))));
    vlTOPp->Endat_SPI_Ctrl__DOT__fsm_stateNext = vlTOPp->__Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext
        [vlTOPp->__Vtableidx4];
    vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT___zz_1 = 0U;
    if (vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_pushing) {
        vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT___zz_1 = 1U;
    }
    vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_pushPtr_willIncrement = 0U;
    if (vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_pushing) {
        vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_pushPtr_willIncrement = 1U;
    }
    vlTOPp->rspdata_valid = vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo_io_pop_valid;
    vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_popping 
        = ((IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo_io_pop_valid) 
           & (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_rdfifo_ready));
    vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_popPtr_valueNext 
        = (0x3fU & ((IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_popPtr_value) 
                    + (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_popPtr_willIncrement)));
    vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_pushPtr_valueNext 
        = (0x3fU & ((IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_pushPtr_value) 
                    + (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_pushPtr_willIncrement)));
    vlTOPp->__Vtableidx2 = vlTOPp->Endat_SPI_Ctrl__DOT__fsm_stateNext;
    vlTOPp->Endat_SPI_Ctrl__DOT__fsm_stateNext_string[0U] 
        = vlTOPp->__Vtable2_Endat_SPI_Ctrl__DOT__fsm_stateNext_string
        [vlTOPp->__Vtableidx2][0U];
    vlTOPp->Endat_SPI_Ctrl__DOT__fsm_stateNext_string[1U] 
        = vlTOPp->__Vtable2_Endat_SPI_Ctrl__DOT__fsm_stateNext_string
        [vlTOPp->__Vtableidx2][1U];
    vlTOPp->Endat_SPI_Ctrl__DOT__fsm_stateNext_string[2U] 
        = vlTOPp->__Vtable2_Endat_SPI_Ctrl__DOT__fsm_stateNext_string
        [vlTOPp->__Vtableidx2][2U];
    vlTOPp->Endat_SPI_Ctrl__DOT__fsm_stateNext_string[3U] 
        = vlTOPp->__Vtable2_Endat_SPI_Ctrl__DOT__fsm_stateNext_string
        [vlTOPp->__Vtableidx2][3U];
    vlTOPp->Endat_SPI_Ctrl__DOT__fsm_stateNext_string[4U] 
        = vlTOPp->__Vtable2_Endat_SPI_Ctrl__DOT__fsm_stateNext_string
        [vlTOPp->__Vtableidx2][4U];
    vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_pushPtr_valueNext 
        = (0x3fU & ((IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_pushPtr_value) 
                    + (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_pushPtr_willIncrement)));
    vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_popPtr_willIncrement = 0U;
    if (vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_popping) {
        vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_popPtr_willIncrement = 1U;
    }
    vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_popPtr_valueNext 
        = (0x3fU & ((IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_popPtr_value) 
                    + (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_popPtr_willIncrement)));
}

void VEndat_SPI_Ctrl::_eval_initial(VEndat_SPI_Ctrl__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VEndat_SPI_Ctrl::_eval_initial\n"); );
    VEndat_SPI_Ctrl* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__clk = (1U & (~ (IData)(vlTOPp->clk)));
    vlTOPp->__Vclklast__TOP__reset = (1U & (~ (IData)(vlTOPp->reset)));
}

void VEndat_SPI_Ctrl::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VEndat_SPI_Ctrl::final\n"); );
    // Variables
    VEndat_SPI_Ctrl__Syms* __restrict vlSymsp = this->__VlSymsp;
    VEndat_SPI_Ctrl* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VEndat_SPI_Ctrl::_eval_settle(VEndat_SPI_Ctrl__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VEndat_SPI_Ctrl::_eval_settle\n"); );
    VEndat_SPI_Ctrl* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__6(vlSymsp);
    vlTOPp->__Vm_traceActivity = (1U | vlTOPp->__Vm_traceActivity);
}

void VEndat_SPI_Ctrl::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VEndat_SPI_Ctrl::_ctor_var_reset\n"); );
    // Body
    spi_ss = VL_RAND_RESET_I(1);
    spi_sclk = VL_RAND_RESET_I(1);
    spi_mosi = VL_RAND_RESET_I(1);
    spi_miso = VL_RAND_RESET_I(1);
    cmddata_valid = VL_RAND_RESET_I(1);
    cmddata_payload_Identity_Addr = VL_RAND_RESET_I(16);
    cmddata_payload_CmdData_0 = VL_RAND_RESET_I(16);
    cmddata_payload_CmdData_1 = VL_RAND_RESET_I(16);
    cmddata_payload_CmdData_2 = VL_RAND_RESET_I(16);
    cmddata_payload_CmdData_3 = VL_RAND_RESET_I(16);
    cmddata_payload_Bytenumber = VL_RAND_RESET_I(6);
    rspdata_valid = VL_RAND_RESET_I(1);
    rspdata_payload_RspData_0 = VL_RAND_RESET_I(16);
    rspdata_payload_RspData_1 = VL_RAND_RESET_I(16);
    rspdata_payload_RspData_2 = VL_RAND_RESET_I(16);
    rspdata_payload_RspData_3 = VL_RAND_RESET_I(16);
    rspdata_payload_RspData_4 = VL_RAND_RESET_I(16);
    clk = 0;
    reset = 0;
    Endat_SPI_Ctrl__DOT___zz_fsm_spi_cmd_payload = VL_RAND_RESET_I(16);
    Endat_SPI_Ctrl__DOT__fsm_wantStart = VL_RAND_RESET_I(1);
    Endat_SPI_Ctrl__DOT__fsm_Identity_Addr = VL_RAND_RESET_I(16);
    Endat_SPI_Ctrl__DOT__fsm_CmdData_0 = VL_RAND_RESET_I(16);
    Endat_SPI_Ctrl__DOT__fsm_CmdData_1 = VL_RAND_RESET_I(16);
    Endat_SPI_Ctrl__DOT__fsm_CmdData_2 = VL_RAND_RESET_I(16);
    Endat_SPI_Ctrl__DOT__fsm_CmdData_3 = VL_RAND_RESET_I(16);
    Endat_SPI_Ctrl__DOT__fsm_Cycle = VL_RAND_RESET_I(2);
    Endat_SPI_Ctrl__DOT__fsm_counter = VL_RAND_RESET_I(4);
    Endat_SPI_Ctrl__DOT__fsm_rdfifo_ready = VL_RAND_RESET_I(1);
    Endat_SPI_Ctrl__DOT__fsm_spi_cmd_valid = VL_RAND_RESET_I(1);
    Endat_SPI_Ctrl__DOT__fsm_spi_cmd_payload = VL_RAND_RESET_I(16);
    Endat_SPI_Ctrl__DOT__fsm_rspData_0 = VL_RAND_RESET_I(16);
    Endat_SPI_Ctrl__DOT__fsm_rspData_1 = VL_RAND_RESET_I(16);
    Endat_SPI_Ctrl__DOT__fsm_rspData_2 = VL_RAND_RESET_I(16);
    Endat_SPI_Ctrl__DOT__fsm_rspData_3 = VL_RAND_RESET_I(16);
    Endat_SPI_Ctrl__DOT__fsm_rspData_4 = VL_RAND_RESET_I(16);
    Endat_SPI_Ctrl__DOT__fsm_stateReg = VL_RAND_RESET_I(3);
    Endat_SPI_Ctrl__DOT__fsm_stateNext = VL_RAND_RESET_I(3);
    Endat_SPI_Ctrl__DOT__when_Endat_SPI_Ctrl_l183 = VL_RAND_RESET_I(1);
    Endat_SPI_Ctrl__DOT__when_Endat_SPI_Ctrl_l196 = VL_RAND_RESET_I(1);
    Endat_SPI_Ctrl__DOT__when_Endat_SPI_Ctrl_l204 = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(144, Endat_SPI_Ctrl__DOT__fsm_stateReg_string);
    VL_RAND_RESET_W(144, Endat_SPI_Ctrl__DOT__fsm_stateNext_string);
    Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo_io_occupancy = VL_RAND_RESET_I(7);
    Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo_io_pop_valid = VL_RAND_RESET_I(1);
    Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo_io_occupancy = VL_RAND_RESET_I(7);
    Endat_SPI_Ctrl__DOT__spictrl__DOT___zz_fsm_buffer = VL_RAND_RESET_I(17);
    Endat_SPI_Ctrl__DOT__spictrl__DOT__timer_counter = VL_RAND_RESET_I(8);
    Endat_SPI_Ctrl__DOT__spictrl__DOT__timer_reset = VL_RAND_RESET_I(1);
    Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_ready = VL_RAND_RESET_I(1);
    Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_wantStart = VL_RAND_RESET_I(1);
    Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_counter_willIncrement = VL_RAND_RESET_I(1);
    Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_counter_valueNext = VL_RAND_RESET_I(5);
    Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_counter_value = VL_RAND_RESET_I(5);
    Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_buffer = VL_RAND_RESET_I(16);
    Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_ss = VL_RAND_RESET_I(1);
    Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_wr_payload = VL_RAND_RESET_I(16);
    Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_rsp_valid = VL_RAND_RESET_I(1);
    Endat_SPI_Ctrl__DOT__spictrl__DOT___zz_spi_sclk = VL_RAND_RESET_I(1);
    Endat_SPI_Ctrl__DOT__spictrl__DOT___zz_spi_mosi = VL_RAND_RESET_I(1);
    Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_stateReg = VL_RAND_RESET_I(3);
    Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_stateNext = VL_RAND_RESET_I(3);
    VL_RAND_RESET_W(88, Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_stateReg_string);
    VL_RAND_RESET_W(88, Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_stateNext_string);
    Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT___zz_logic_ram_port0 = VL_RAND_RESET_I(16);
    Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT___zz_1 = VL_RAND_RESET_I(1);
    Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_pushPtr_willIncrement = VL_RAND_RESET_I(1);
    Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_pushPtr_valueNext = VL_RAND_RESET_I(6);
    Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_pushPtr_value = VL_RAND_RESET_I(6);
    Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_popPtr_willIncrement = VL_RAND_RESET_I(1);
    Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_popPtr_valueNext = VL_RAND_RESET_I(6);
    Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_popPtr_value = VL_RAND_RESET_I(6);
    Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_ptrMatch = VL_RAND_RESET_I(1);
    Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_risingOccupancy = VL_RAND_RESET_I(1);
    Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_pushing = VL_RAND_RESET_I(1);
    Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_popping = VL_RAND_RESET_I(1);
    Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_full = VL_RAND_RESET_I(1);
    Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT___zz_io_pop_valid = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<64; ++__Vi0) {
            Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_ram[__Vi0] = VL_RAND_RESET_I(16);
    }}
    Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT___zz_logic_ram_port0 = VL_RAND_RESET_I(16);
    Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT___zz_1 = VL_RAND_RESET_I(1);
    Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_pushPtr_willIncrement = VL_RAND_RESET_I(1);
    Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_pushPtr_valueNext = VL_RAND_RESET_I(6);
    Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_pushPtr_value = VL_RAND_RESET_I(6);
    Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_popPtr_willIncrement = VL_RAND_RESET_I(1);
    Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_popPtr_valueNext = VL_RAND_RESET_I(6);
    Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_popPtr_value = VL_RAND_RESET_I(6);
    Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_ptrMatch = VL_RAND_RESET_I(1);
    Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_risingOccupancy = VL_RAND_RESET_I(1);
    Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_pushing = VL_RAND_RESET_I(1);
    Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_popping = VL_RAND_RESET_I(1);
    Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_full = VL_RAND_RESET_I(1);
    Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT___zz_io_pop_valid = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<64; ++__Vi0) {
            Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_ram[__Vi0] = VL_RAND_RESET_I(16);
    }}
    __Vtableidx1 = 0;
    VL_CONST_W_5X(144,__Vtable1_Endat_SPI_Ctrl__DOT__fsm_stateReg_string[0],0x0000424f,0x4f542020,0x20202020,0x20202020,0x20202020);
    VL_CONST_W_5X(144,__Vtable1_Endat_SPI_Ctrl__DOT__fsm_stateReg_string[1],0x0000496e,0x69745f53,0x74617274,0x20202020,0x20202020);
    VL_CONST_W_5X(144,__Vtable1_Endat_SPI_Ctrl__DOT__fsm_stateReg_string[2],0x00005365,0x6e645f49,0x64656e74,0x6974795f,0x41646472);
    VL_CONST_W_5X(144,__Vtable1_Endat_SPI_Ctrl__DOT__fsm_stateReg_string[3],0x00005365,0x6e645f52,0x65674461,0x74612020,0x20202020);
    VL_CONST_W_5X(144,__Vtable1_Endat_SPI_Ctrl__DOT__fsm_stateReg_string[4],0x00005761,0x69745f52,0x73702020,0x20202020,0x20202020);
    VL_CONST_W_5X(144,__Vtable1_Endat_SPI_Ctrl__DOT__fsm_stateReg_string[5],0x00005264,0x5f527370,0x20202020,0x20202020,0x20202020);
    VL_CONST_W_5X(144,__Vtable1_Endat_SPI_Ctrl__DOT__fsm_stateReg_string[6],0x00003f3f,0x3f3f3f3f,0x3f3f3f3f,0x3f3f3f3f,0x3f3f3f3f);
    VL_CONST_W_5X(144,__Vtable1_Endat_SPI_Ctrl__DOT__fsm_stateReg_string[7],0x00003f3f,0x3f3f3f3f,0x3f3f3f3f,0x3f3f3f3f,0x3f3f3f3f);
    __Vtableidx2 = 0;
    VL_CONST_W_5X(144,__Vtable2_Endat_SPI_Ctrl__DOT__fsm_stateNext_string[0],0x0000424f,0x4f542020,0x20202020,0x20202020,0x20202020);
    VL_CONST_W_5X(144,__Vtable2_Endat_SPI_Ctrl__DOT__fsm_stateNext_string[1],0x0000496e,0x69745f53,0x74617274,0x20202020,0x20202020);
    VL_CONST_W_5X(144,__Vtable2_Endat_SPI_Ctrl__DOT__fsm_stateNext_string[2],0x00005365,0x6e645f49,0x64656e74,0x6974795f,0x41646472);
    VL_CONST_W_5X(144,__Vtable2_Endat_SPI_Ctrl__DOT__fsm_stateNext_string[3],0x00005365,0x6e645f52,0x65674461,0x74612020,0x20202020);
    VL_CONST_W_5X(144,__Vtable2_Endat_SPI_Ctrl__DOT__fsm_stateNext_string[4],0x00005761,0x69745f52,0x73702020,0x20202020,0x20202020);
    VL_CONST_W_5X(144,__Vtable2_Endat_SPI_Ctrl__DOT__fsm_stateNext_string[5],0x00005264,0x5f527370,0x20202020,0x20202020,0x20202020);
    VL_CONST_W_5X(144,__Vtable2_Endat_SPI_Ctrl__DOT__fsm_stateNext_string[6],0x00003f3f,0x3f3f3f3f,0x3f3f3f3f,0x3f3f3f3f,0x3f3f3f3f);
    VL_CONST_W_5X(144,__Vtable2_Endat_SPI_Ctrl__DOT__fsm_stateNext_string[7],0x00003f3f,0x3f3f3f3f,0x3f3f3f3f,0x3f3f3f3f,0x3f3f3f3f);
    __Vtableidx3 = 0;
    __Vtable3_Endat_SPI_Ctrl__DOT__fsm_wantStart[0] = 1U;
    __Vtable3_Endat_SPI_Ctrl__DOT__fsm_wantStart[1] = 0U;
    __Vtable3_Endat_SPI_Ctrl__DOT__fsm_wantStart[2] = 0U;
    __Vtable3_Endat_SPI_Ctrl__DOT__fsm_wantStart[3] = 0U;
    __Vtable3_Endat_SPI_Ctrl__DOT__fsm_wantStart[4] = 0U;
    __Vtable3_Endat_SPI_Ctrl__DOT__fsm_wantStart[5] = 0U;
    __Vtable3_Endat_SPI_Ctrl__DOT__fsm_wantStart[6] = 1U;
    __Vtable3_Endat_SPI_Ctrl__DOT__fsm_wantStart[7] = 1U;
    __Vtableidx4 = 0;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[0] = 0U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[1] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[2] = 3U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[3] = 4U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[4] = 4U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[5] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[6] = 6U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[7] = 7U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[8] = 0U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[9] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[10] = 3U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[11] = 4U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[12] = 4U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[13] = 5U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[14] = 6U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[15] = 7U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[16] = 0U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[17] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[18] = 3U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[19] = 4U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[20] = 5U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[21] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[22] = 6U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[23] = 7U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[24] = 0U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[25] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[26] = 3U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[27] = 4U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[28] = 5U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[29] = 5U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[30] = 6U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[31] = 7U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[32] = 0U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[33] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[34] = 3U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[35] = 3U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[36] = 4U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[37] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[38] = 6U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[39] = 7U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[40] = 0U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[41] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[42] = 3U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[43] = 3U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[44] = 4U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[45] = 5U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[46] = 6U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[47] = 7U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[48] = 0U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[49] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[50] = 3U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[51] = 3U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[52] = 5U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[53] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[54] = 6U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[55] = 7U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[56] = 0U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[57] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[58] = 3U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[59] = 3U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[60] = 5U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[61] = 5U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[62] = 6U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[63] = 7U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[64] = 0U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[65] = 2U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[66] = 3U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[67] = 4U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[68] = 4U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[69] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[70] = 6U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[71] = 7U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[72] = 0U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[73] = 2U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[74] = 3U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[75] = 4U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[76] = 4U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[77] = 5U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[78] = 6U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[79] = 7U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[80] = 0U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[81] = 2U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[82] = 3U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[83] = 4U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[84] = 5U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[85] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[86] = 6U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[87] = 7U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[88] = 0U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[89] = 2U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[90] = 3U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[91] = 4U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[92] = 5U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[93] = 5U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[94] = 6U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[95] = 7U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[96] = 0U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[97] = 2U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[98] = 3U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[99] = 3U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[100] = 4U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[101] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[102] = 6U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[103] = 7U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[104] = 0U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[105] = 2U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[106] = 3U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[107] = 3U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[108] = 4U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[109] = 5U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[110] = 6U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[111] = 7U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[112] = 0U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[113] = 2U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[114] = 3U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[115] = 3U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[116] = 5U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[117] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[118] = 6U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[119] = 7U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[120] = 0U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[121] = 2U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[122] = 3U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[123] = 3U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[124] = 5U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[125] = 5U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[126] = 6U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[127] = 7U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[128] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[129] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[130] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[131] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[132] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[133] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[134] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[135] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[136] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[137] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[138] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[139] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[140] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[141] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[142] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[143] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[144] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[145] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[146] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[147] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[148] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[149] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[150] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[151] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[152] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[153] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[154] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[155] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[156] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[157] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[158] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[159] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[160] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[161] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[162] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[163] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[164] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[165] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[166] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[167] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[168] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[169] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[170] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[171] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[172] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[173] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[174] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[175] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[176] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[177] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[178] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[179] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[180] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[181] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[182] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[183] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[184] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[185] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[186] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[187] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[188] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[189] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[190] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[191] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[192] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[193] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[194] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[195] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[196] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[197] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[198] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[199] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[200] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[201] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[202] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[203] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[204] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[205] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[206] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[207] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[208] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[209] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[210] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[211] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[212] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[213] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[214] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[215] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[216] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[217] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[218] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[219] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[220] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[221] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[222] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[223] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[224] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[225] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[226] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[227] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[228] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[229] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[230] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[231] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[232] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[233] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[234] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[235] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[236] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[237] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[238] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[239] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[240] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[241] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[242] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[243] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[244] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[245] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[246] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[247] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[248] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[249] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[250] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[251] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[252] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[253] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[254] = 1U;
    __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[255] = 1U;
    __Vtableidx5 = 0;
    VL_CONST_W_3X(88,__Vtable5_Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_stateReg_string[0],0x00424f4f,0x54202020,0x20202020);
    VL_CONST_W_3X(88,__Vtable5_Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_stateReg_string[1],0x00496e69,0x745f5374,0x61727420);
    VL_CONST_W_3X(88,__Vtable5_Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_stateReg_string[2],0x00416374,0x6976655f,0x43532020);
    VL_CONST_W_3X(88,__Vtable5_Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_stateReg_string[3],0x0053656e,0x645f4461,0x74612020);
    VL_CONST_W_3X(88,__Vtable5_Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_stateReg_string[4],0x00446973,0x61626c65,0x5f435320);
    VL_CONST_W_3X(88,__Vtable5_Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_stateReg_string[5],0x0044756d,0x6d795f53,0x74617465);
    VL_CONST_W_3X(88,__Vtable5_Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_stateReg_string[6],0x003f3f3f,0x3f3f3f3f,0x3f3f3f3f);
    VL_CONST_W_3X(88,__Vtable5_Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_stateReg_string[7],0x003f3f3f,0x3f3f3f3f,0x3f3f3f3f);
    __Vtableidx6 = 0;
    VL_CONST_W_3X(88,__Vtable6_Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_stateNext_string[0],0x00424f4f,0x54202020,0x20202020);
    VL_CONST_W_3X(88,__Vtable6_Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_stateNext_string[1],0x00496e69,0x745f5374,0x61727420);
    VL_CONST_W_3X(88,__Vtable6_Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_stateNext_string[2],0x00416374,0x6976655f,0x43532020);
    VL_CONST_W_3X(88,__Vtable6_Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_stateNext_string[3],0x0053656e,0x645f4461,0x74612020);
    VL_CONST_W_3X(88,__Vtable6_Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_stateNext_string[4],0x00446973,0x61626c65,0x5f435320);
    VL_CONST_W_3X(88,__Vtable6_Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_stateNext_string[5],0x0044756d,0x6d795f53,0x74617465);
    VL_CONST_W_3X(88,__Vtable6_Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_stateNext_string[6],0x003f3f3f,0x3f3f3f3f,0x3f3f3f3f);
    VL_CONST_W_3X(88,__Vtable6_Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_stateNext_string[7],0x003f3f3f,0x3f3f3f3f,0x3f3f3f3f);
    __Vtableidx7 = 0;
    __Vtable7_Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_wantStart[0] = 1U;
    __Vtable7_Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_wantStart[1] = 0U;
    __Vtable7_Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_wantStart[2] = 0U;
    __Vtable7_Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_wantStart[3] = 0U;
    __Vtable7_Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_wantStart[4] = 0U;
    __Vtable7_Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_wantStart[5] = 0U;
    __Vtable7_Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_wantStart[6] = 1U;
    __Vtable7_Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_wantStart[7] = 1U;
    __Vtableidx8 = 0;
    __Vtable8_Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_counter_willIncrement[0] = 0U;
    __Vtable8_Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_counter_willIncrement[1] = 0U;
    __Vtable8_Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_counter_willIncrement[2] = 0U;
    __Vtable8_Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_counter_willIncrement[3] = 0U;
    __Vtable8_Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_counter_willIncrement[4] = 0U;
    __Vtable8_Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_counter_willIncrement[5] = 0U;
    __Vtable8_Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_counter_willIncrement[6] = 0U;
    __Vtable8_Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_counter_willIncrement[7] = 0U;
    __Vtable8_Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_counter_willIncrement[8] = 0U;
    __Vtable8_Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_counter_willIncrement[9] = 0U;
    __Vtable8_Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_counter_willIncrement[10] = 0U;
    __Vtable8_Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_counter_willIncrement[11] = 1U;
    __Vtable8_Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_counter_willIncrement[12] = 0U;
    __Vtable8_Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_counter_willIncrement[13] = 0U;
    __Vtable8_Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_counter_willIncrement[14] = 0U;
    __Vtable8_Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_counter_willIncrement[15] = 0U;
    __Vdly__Endat_SPI_Ctrl__DOT__fsm_Identity_Addr = VL_RAND_RESET_I(16);
    __Vdly__Endat_SPI_Ctrl__DOT__fsm_counter = VL_RAND_RESET_I(4);
    __Vdly__Endat_SPI_Ctrl__DOT__spictrl__DOT__timer_counter = VL_RAND_RESET_I(8);
    __Vdlyvdim0__Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_ram__v0 = 0;
    __Vdlyvval__Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_ram__v0 = VL_RAND_RESET_I(16);
    __Vdlyvset__Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_ram__v0 = 0;
    __Vdlyvset__Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_ram__v0 = 0;
    __Vm_traceActivity = 0;
}
