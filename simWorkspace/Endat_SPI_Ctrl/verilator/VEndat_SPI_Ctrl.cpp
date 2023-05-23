// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VEndat_SPI_Ctrl.h for the primary calling header

#include "VEndat_SPI_Ctrl.h"
#include "VEndat_SPI_Ctrl__Syms.h"

//==========

void VEndat_SPI_Ctrl::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VEndat_SPI_Ctrl::eval\n"); );
    VEndat_SPI_Ctrl__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    VEndat_SPI_Ctrl* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
#ifdef VM_TRACE
    // Tracing
#endif  // VM_TRACE
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        vlSymsp->__Vm_activity = true;
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("D:/SCALA/Xil_Master/tmp/job_1/Endat_SPI_Ctrl.v", 6, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void VEndat_SPI_Ctrl::_eval_initial_loop(VEndat_SPI_Ctrl__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("D:/SCALA/Xil_Master/tmp/job_1/Endat_SPI_Ctrl.v", 6, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void VEndat_SPI_Ctrl::_sequent__TOP__2(VEndat_SPI_Ctrl__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VEndat_SPI_Ctrl::_sequent__TOP__2\n"); );
    VEndat_SPI_Ctrl* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vdly__Endat_SPI_Ctrl__DOT__spictrl__DOT__timer_counter 
        = vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__timer_counter;
    vlTOPp->__Vdlyvset__Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_ram__v0 = 0U;
    vlTOPp->__Vdlyvset__Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_ram__v0 = 0U;
    if ((1U & (~ ((IData)(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_stateReg) 
                  >> 2U)))) {
        if ((1U & (~ ((IData)(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_stateReg) 
                      >> 1U)))) {
            if ((1U & (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_stateReg))) {
                if (vlTOPp->cmddata_valid) {
                    vlTOPp->Endat_SPI_Ctrl__DOT__fsm_CmdData_3 
                        = vlTOPp->cmddata_payload_CmdData_3;
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_stateReg) 
                  >> 2U)))) {
        if ((1U & (~ ((IData)(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_stateReg) 
                      >> 1U)))) {
            if ((1U & (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_stateReg))) {
                if (vlTOPp->cmddata_valid) {
                    vlTOPp->Endat_SPI_Ctrl__DOT__fsm_CmdData_2 
                        = vlTOPp->cmddata_payload_CmdData_2;
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_stateReg) 
                  >> 2U)))) {
        if ((1U & (~ ((IData)(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_stateReg) 
                      >> 1U)))) {
            if ((1U & (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_stateReg))) {
                if (vlTOPp->cmddata_valid) {
                    vlTOPp->Endat_SPI_Ctrl__DOT__fsm_CmdData_0 
                        = vlTOPp->cmddata_payload_CmdData_0;
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_stateReg) 
                  >> 2U)))) {
        if ((1U & (~ ((IData)(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_stateReg) 
                      >> 1U)))) {
            if ((1U & (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_stateReg))) {
                if (vlTOPp->cmddata_valid) {
                    vlTOPp->Endat_SPI_Ctrl__DOT__fsm_CmdData_1 
                        = vlTOPp->cmddata_payload_CmdData_1;
                }
            }
        }
    }
    if ((4U & (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_stateReg))) {
        if ((1U & (~ ((IData)(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_stateReg) 
                      >> 1U)))) {
            if ((1U & (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_stateReg))) {
                if (vlTOPp->Endat_SPI_Ctrl__DOT__when_Endat_SPI_Ctrl_l204) {
                    if ((1U & ((IData)(1U) << (7U & (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_counter))))) {
                        vlTOPp->Endat_SPI_Ctrl__DOT__fsm_rspData_0 
                            = vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT___zz_logic_ram_port0;
                    }
                }
            }
        }
    }
    if ((4U & (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_stateReg))) {
        if ((1U & (~ ((IData)(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_stateReg) 
                      >> 1U)))) {
            if ((1U & (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_stateReg))) {
                if (vlTOPp->Endat_SPI_Ctrl__DOT__when_Endat_SPI_Ctrl_l204) {
                    if ((2U & ((IData)(1U) << (7U & (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_counter))))) {
                        vlTOPp->Endat_SPI_Ctrl__DOT__fsm_rspData_1 
                            = vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT___zz_logic_ram_port0;
                    }
                }
            }
        }
    }
    if ((4U & (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_stateReg))) {
        if ((1U & (~ ((IData)(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_stateReg) 
                      >> 1U)))) {
            if ((1U & (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_stateReg))) {
                if (vlTOPp->Endat_SPI_Ctrl__DOT__when_Endat_SPI_Ctrl_l204) {
                    if ((0x10U & ((IData)(1U) << (7U 
                                                  & (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_counter))))) {
                        vlTOPp->Endat_SPI_Ctrl__DOT__fsm_rspData_4 
                            = vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT___zz_logic_ram_port0;
                    }
                }
            }
        }
    }
    if ((4U & (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_stateReg))) {
        if ((1U & (~ ((IData)(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_stateReg) 
                      >> 1U)))) {
            if ((1U & (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_stateReg))) {
                if (vlTOPp->Endat_SPI_Ctrl__DOT__when_Endat_SPI_Ctrl_l204) {
                    if ((4U & ((IData)(1U) << (7U & (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_counter))))) {
                        vlTOPp->Endat_SPI_Ctrl__DOT__fsm_rspData_2 
                            = vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT___zz_logic_ram_port0;
                    }
                }
            }
        }
    }
    if ((4U & (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_stateReg))) {
        if ((1U & (~ ((IData)(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_stateReg) 
                      >> 1U)))) {
            if ((1U & (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_stateReg))) {
                if (vlTOPp->Endat_SPI_Ctrl__DOT__when_Endat_SPI_Ctrl_l204) {
                    if ((8U & ((IData)(1U) << (7U & (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_counter))))) {
                        vlTOPp->Endat_SPI_Ctrl__DOT__fsm_rspData_3 
                            = vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT___zz_logic_ram_port0;
                    }
                }
            }
        }
    }
    vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_ready = 0U;
    if ((1U & (~ ((IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_stateReg) 
                  >> 2U)))) {
        if ((2U & (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_stateReg))) {
            if ((1U & (~ (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_stateReg)))) {
                if ((0x64U == (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__timer_counter))) {
                    vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_ready = 1U;
                }
            }
        }
    }
    vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_rsp_valid = 0U;
    if ((4U & (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_stateReg))) {
        if ((1U & (~ ((IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_stateReg) 
                      >> 1U)))) {
            if ((1U & (~ (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_stateReg)))) {
                if ((0x64U == (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__timer_counter))) {
                    vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_rsp_valid = 1U;
                }
            }
        }
    }
    vlTOPp->Endat_SPI_Ctrl__DOT__fsm_spi_cmd_valid = 0U;
    if ((1U & (~ ((IData)(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_stateReg) 
                  >> 2U)))) {
        if ((2U & (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_stateReg))) {
            vlTOPp->Endat_SPI_Ctrl__DOT__fsm_spi_cmd_valid 
                = (1U & ((~ (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_stateReg)) 
                         | (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__when_Endat_SPI_Ctrl_l183)));
        }
    }
    vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT___zz_spi_sclk 
        = (1U & (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_counter_value));
    vlTOPp->__Vdly__Endat_SPI_Ctrl__DOT__spictrl__DOT__timer_counter 
        = (0xffU & ((IData)(1U) + (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__timer_counter)));
    if (vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__timer_reset) {
        vlTOPp->__Vdly__Endat_SPI_Ctrl__DOT__spictrl__DOT__timer_counter = 0U;
    }
    vlTOPp->Endat_SPI_Ctrl__DOT__fsm_rdfifo_ready = 0U;
    if ((4U & (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_stateReg))) {
        if ((1U & (~ ((IData)(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_stateReg) 
                      >> 1U)))) {
            if ((1U & (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_stateReg))) {
                if ((0U != (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo_io_occupancy))) {
                    vlTOPp->Endat_SPI_Ctrl__DOT__fsm_rdfifo_ready = 1U;
                }
            } else {
                if (vlTOPp->Endat_SPI_Ctrl__DOT__when_Endat_SPI_Ctrl_l196) {
                    vlTOPp->Endat_SPI_Ctrl__DOT__fsm_rdfifo_ready = 1U;
                }
            }
        }
    } else {
        if ((1U & (~ ((IData)(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_stateReg) 
                      >> 1U)))) {
            if ((1U & (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_stateReg))) {
                if ((1U & (~ (IData)(vlTOPp->cmddata_valid)))) {
                    vlTOPp->Endat_SPI_Ctrl__DOT__fsm_rdfifo_ready = 1U;
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_stateReg) 
                  >> 2U)))) {
        if ((1U & (~ ((IData)(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_stateReg) 
                      >> 1U)))) {
            if ((1U & (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_stateReg))) {
                if (vlTOPp->cmddata_valid) {
                    vlTOPp->Endat_SPI_Ctrl__DOT__fsm_Cycle 
                        = (3U & ((IData)(vlTOPp->cmddata_payload_Bytenumber) 
                                 >> 1U));
                }
            }
        }
    }
    vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT___zz_spi_mosi 
        = (1U & ((IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_wr_payload) 
                 >> (0xfU & ((IData)(0xfU) - ((IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_counter_value) 
                                              >> 1U)))));
    if (vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT___zz_1) {
        vlTOPp->__Vdlyvval__Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_ram__v0 
            = vlTOPp->Endat_SPI_Ctrl__DOT__fsm_spi_cmd_payload;
        vlTOPp->__Vdlyvset__Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_ram__v0 = 1U;
        vlTOPp->__Vdlyvdim0__Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_ram__v0 
            = vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_pushPtr_value;
    }
}

VL_INLINE_OPT void VEndat_SPI_Ctrl::_sequent__TOP__3(VEndat_SPI_Ctrl__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VEndat_SPI_Ctrl::_sequent__TOP__3\n"); );
    VEndat_SPI_Ctrl* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*5:0*/ __Vdlyvdim0__Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_ram__v0;
    SData/*15:0*/ __Vdlyvval__Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_ram__v0;
    // Body
    if (vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT___zz_1) {
        __Vdlyvval__Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_ram__v0 
            = vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_buffer;
        vlTOPp->__Vdlyvset__Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_ram__v0 = 1U;
        __Vdlyvdim0__Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_ram__v0 
            = vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_pushPtr_value;
    }
    vlTOPp->rspdata_payload_RspData_0 = vlTOPp->Endat_SPI_Ctrl__DOT__fsm_rspData_0;
    vlTOPp->rspdata_payload_RspData_1 = vlTOPp->Endat_SPI_Ctrl__DOT__fsm_rspData_1;
    vlTOPp->rspdata_payload_RspData_4 = vlTOPp->Endat_SPI_Ctrl__DOT__fsm_rspData_4;
    vlTOPp->rspdata_payload_RspData_2 = vlTOPp->Endat_SPI_Ctrl__DOT__fsm_rspData_2;
    vlTOPp->rspdata_payload_RspData_3 = vlTOPp->Endat_SPI_Ctrl__DOT__fsm_rspData_3;
    vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT___zz_logic_ram_port0 
        = vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_ram
        [vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_popPtr_valueNext];
    vlTOPp->spi_sclk = vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT___zz_spi_sclk;
    vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__timer_reset = 0U;
    if ((4U & (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_stateReg))) {
        if ((1U & (~ ((IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_stateReg) 
                      >> 1U)))) {
            if ((1U & (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_stateReg))) {
                if ((0xc8U == (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__timer_counter))) {
                    vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__timer_reset = 1U;
                }
            } else {
                if ((0x64U == (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__timer_counter))) {
                    vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__timer_reset = 1U;
                }
            }
        }
    } else {
        if ((2U & (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_stateReg))) {
            if ((1U & (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_stateReg))) {
                if ((0xaU == (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__timer_counter))) {
                    vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__timer_reset = 1U;
                }
            } else {
                if ((0x64U == (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__timer_counter))) {
                    vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__timer_reset = 1U;
                }
            }
        } else {
            if ((1U & (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_stateReg))) {
                if ((0U != (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo_io_occupancy))) {
                    vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__timer_reset = 1U;
                }
            }
        }
    }
    vlTOPp->spi_mosi = vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT___zz_spi_mosi;
    if ((1U & (~ ((IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_stateReg) 
                  >> 2U)))) {
        if ((2U & (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_stateReg))) {
            if ((1U & (~ (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_stateReg)))) {
                if ((0x64U == (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__timer_counter))) {
                    vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_wr_payload 
                        = vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT___zz_logic_ram_port0;
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_stateReg) 
                  >> 2U)))) {
        if ((2U & (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_stateReg))) {
            if ((1U & (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_stateReg))) {
                if ((0xaU == (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__timer_counter))) {
                    if ((1U & (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_counter_value))) {
                        vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_buffer 
                            = (0xffffU & vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT___zz_fsm_buffer);
                    }
                }
            }
        }
    }
    if (vlTOPp->__Vdlyvset__Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_ram__v0) {
        vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_ram[__Vdlyvdim0__Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_ram__v0] 
            = __Vdlyvval__Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_ram__v0;
    }
    vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT___zz_logic_ram_port0 
        = vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_ram
        [vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_popPtr_valueNext];
    if (vlTOPp->__Vdlyvset__Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_ram__v0) {
        vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_ram[vlTOPp->__Vdlyvdim0__Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_ram__v0] 
            = vlTOPp->__Vdlyvval__Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_ram__v0;
    }
}

VL_INLINE_OPT void VEndat_SPI_Ctrl::_sequent__TOP__4(VEndat_SPI_Ctrl__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VEndat_SPI_Ctrl::_sequent__TOP__4\n"); );
    VEndat_SPI_Ctrl* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vdly__Endat_SPI_Ctrl__DOT__fsm_Identity_Addr 
        = vlTOPp->Endat_SPI_Ctrl__DOT__fsm_Identity_Addr;
    vlTOPp->__Vdly__Endat_SPI_Ctrl__DOT__fsm_counter 
        = vlTOPp->Endat_SPI_Ctrl__DOT__fsm_counter;
    if (vlTOPp->reset) {
        vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_counter_value = 0U;
        vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_ss = 1U;
    } else {
        vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_counter_value 
            = vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_counter_valueNext;
        if ((4U & (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_stateReg))) {
            if ((1U & (~ ((IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_stateReg) 
                          >> 1U)))) {
                if ((1U & (~ (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_stateReg)))) {
                    if ((0x64U == (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__timer_counter))) {
                        vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_ss = 1U;
                    }
                }
            }
        } else {
            if ((2U & (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_stateReg))) {
                if ((1U & (~ (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_stateReg)))) {
                    if ((0x64U == (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__timer_counter))) {
                        vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_counter_value = 0U;
                    }
                }
            } else {
                if ((1U & (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_stateReg))) {
                    if ((0U != (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo_io_occupancy))) {
                        vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_ss = 0U;
                    }
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->__Vdly__Endat_SPI_Ctrl__DOT__fsm_Identity_Addr = 0U;
        vlTOPp->__Vdly__Endat_SPI_Ctrl__DOT__fsm_counter = 0U;
        vlTOPp->Endat_SPI_Ctrl__DOT__fsm_spi_cmd_payload = 0U;
    } else {
        if ((4U & (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_stateReg))) {
            if ((1U & (~ ((IData)(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_stateReg) 
                          >> 1U)))) {
                if ((1U & (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_stateReg))) {
                    if (vlTOPp->Endat_SPI_Ctrl__DOT__when_Endat_SPI_Ctrl_l204) {
                        vlTOPp->__Vdly__Endat_SPI_Ctrl__DOT__fsm_counter 
                            = (0xfU & ((IData)(1U) 
                                       + (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_counter)));
                    }
                }
            }
        } else {
            if ((2U & (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_stateReg))) {
                if ((1U & (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_stateReg))) {
                    if (vlTOPp->Endat_SPI_Ctrl__DOT__when_Endat_SPI_Ctrl_l183) {
                        vlTOPp->__Vdly__Endat_SPI_Ctrl__DOT__fsm_counter 
                            = (0xfU & ((IData)(1U) 
                                       + (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_counter)));
                        vlTOPp->Endat_SPI_Ctrl__DOT__fsm_spi_cmd_payload 
                            = vlTOPp->Endat_SPI_Ctrl__DOT___zz_fsm_spi_cmd_payload;
                    } else {
                        vlTOPp->__Vdly__Endat_SPI_Ctrl__DOT__fsm_counter = 0U;
                    }
                } else {
                    vlTOPp->Endat_SPI_Ctrl__DOT__fsm_spi_cmd_payload 
                        = vlTOPp->Endat_SPI_Ctrl__DOT__fsm_Identity_Addr;
                }
            } else {
                if ((1U & (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_stateReg))) {
                    if (vlTOPp->cmddata_valid) {
                        vlTOPp->__Vdly__Endat_SPI_Ctrl__DOT__fsm_Identity_Addr 
                            = vlTOPp->cmddata_payload_Identity_Addr;
                        vlTOPp->__Vdly__Endat_SPI_Ctrl__DOT__fsm_counter = 0U;
                    }
                }
            }
        }
    }
}

VL_INLINE_OPT void VEndat_SPI_Ctrl::_sequent__TOP__5(VEndat_SPI_Ctrl__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VEndat_SPI_Ctrl::_sequent__TOP__5\n"); );
    VEndat_SPI_Ctrl* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (vlTOPp->reset) {
        vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_risingOccupancy = 0U;
    } else {
        if (((IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_pushing) 
             != (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_popping))) {
            vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_risingOccupancy 
                = vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_pushing;
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_risingOccupancy = 0U;
    } else {
        if (((IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_pushing) 
             != (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_popping))) {
            vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_risingOccupancy 
                = vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_pushing;
        }
    }
    vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_popPtr_value 
        = ((IData)(vlTOPp->reset) ? 0U : (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_popPtr_valueNext));
    vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT___zz_io_pop_valid 
        = ((~ (IData)(vlTOPp->reset)) & ((IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_popPtr_valueNext) 
                                         == (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_pushPtr_value)));
    vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_popPtr_value 
        = ((IData)(vlTOPp->reset) ? 0U : (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_popPtr_valueNext));
    vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT___zz_io_pop_valid 
        = ((~ (IData)(vlTOPp->reset)) & ((IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_popPtr_valueNext) 
                                         == (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_pushPtr_value)));
    vlTOPp->Endat_SPI_Ctrl__DOT__fsm_Identity_Addr 
        = vlTOPp->__Vdly__Endat_SPI_Ctrl__DOT__fsm_Identity_Addr;
    vlTOPp->Endat_SPI_Ctrl__DOT__fsm_counter = vlTOPp->__Vdly__Endat_SPI_Ctrl__DOT__fsm_counter;
    vlTOPp->spi_ss = vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_ss;
    vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_stateReg 
        = ((IData)(vlTOPp->reset) ? 0U : (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_stateNext));
    vlTOPp->Endat_SPI_Ctrl__DOT__when_Endat_SPI_Ctrl_l204 
        = ((IData)(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_counter) 
           < (3U & ((IData)(1U) + (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_Cycle))));
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
    vlTOPp->Endat_SPI_Ctrl__DOT__fsm_stateReg = ((IData)(vlTOPp->reset)
                                                  ? 0U
                                                  : (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__fsm_stateNext));
    vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_pushPtr_value 
        = ((IData)(vlTOPp->reset) ? 0U : (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_pushPtr_valueNext));
    vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_pushPtr_value 
        = ((IData)(vlTOPp->reset) ? 0U : (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_pushPtr_valueNext));
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
    vlTOPp->__Vtableidx7 = vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_stateReg;
    vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_wantStart 
        = vlTOPp->__Vtable7_Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_wantStart
        [vlTOPp->__Vtableidx7];
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
    vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_ptrMatch 
        = ((IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_pushPtr_value) 
           == (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__wr_fifo__DOT__logic_popPtr_value));
    vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_ptrMatch 
        = ((IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_pushPtr_value) 
           == (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__rd_fifo__DOT__logic_popPtr_value));
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

VL_INLINE_OPT void VEndat_SPI_Ctrl::_combo__TOP__7(VEndat_SPI_Ctrl__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VEndat_SPI_Ctrl::_combo__TOP__7\n"); );
    VEndat_SPI_Ctrl* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT___zz_fsm_buffer 
        = (((IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_buffer) 
            << 1U) | (IData)(vlTOPp->spi_miso));
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
}

VL_INLINE_OPT void VEndat_SPI_Ctrl::_sequent__TOP__8(VEndat_SPI_Ctrl__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VEndat_SPI_Ctrl::_sequent__TOP__8\n"); );
    VEndat_SPI_Ctrl* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__timer_counter 
        = vlTOPp->__Vdly__Endat_SPI_Ctrl__DOT__spictrl__DOT__timer_counter;
}

VL_INLINE_OPT void VEndat_SPI_Ctrl::_sequent__TOP__9(VEndat_SPI_Ctrl__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VEndat_SPI_Ctrl::_sequent__TOP__9\n"); );
    VEndat_SPI_Ctrl* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vtableidx8 = (((0xaU == (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__timer_counter)) 
                             << 3U) | (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_stateReg));
    vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_counter_willIncrement 
        = vlTOPp->__Vtable8_Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_counter_willIncrement
        [vlTOPp->__Vtableidx8];
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
    vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_counter_valueNext 
        = (0x1fU & ((IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_counter_value) 
                    + (IData)(vlTOPp->Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_counter_willIncrement)));
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
}

void VEndat_SPI_Ctrl::_eval(VEndat_SPI_Ctrl__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VEndat_SPI_Ctrl::_eval\n"); );
    VEndat_SPI_Ctrl* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
        vlTOPp->__Vm_traceActivity = (2U | vlTOPp->__Vm_traceActivity);
        vlTOPp->_sequent__TOP__2(vlSymsp);
        vlTOPp->_sequent__TOP__3(vlSymsp);
    }
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
         | ((IData)(vlTOPp->reset) & (~ (IData)(vlTOPp->__Vclklast__TOP__reset))))) {
        vlTOPp->_sequent__TOP__4(vlSymsp);
        vlTOPp->__Vm_traceActivity = (4U | vlTOPp->__Vm_traceActivity);
        vlTOPp->_sequent__TOP__5(vlSymsp);
    }
    vlTOPp->_combo__TOP__7(vlSymsp);
    vlTOPp->__Vm_traceActivity = (8U | vlTOPp->__Vm_traceActivity);
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
        vlTOPp->_sequent__TOP__8(vlSymsp);
        vlTOPp->__Vm_traceActivity = (0x10U | vlTOPp->__Vm_traceActivity);
    }
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
         | ((IData)(vlTOPp->reset) & (~ (IData)(vlTOPp->__Vclklast__TOP__reset))))) {
        vlTOPp->_sequent__TOP__9(vlSymsp);
        vlTOPp->__Vm_traceActivity = (0x20U | vlTOPp->__Vm_traceActivity);
    }
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP__reset = vlTOPp->reset;
}

VL_INLINE_OPT QData VEndat_SPI_Ctrl::_change_request(VEndat_SPI_Ctrl__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VEndat_SPI_Ctrl::_change_request\n"); );
    VEndat_SPI_Ctrl* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData VEndat_SPI_Ctrl::_change_request_1(VEndat_SPI_Ctrl__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VEndat_SPI_Ctrl::_change_request_1\n"); );
    VEndat_SPI_Ctrl* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void VEndat_SPI_Ctrl::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VEndat_SPI_Ctrl::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((spi_miso & 0xfeU))) {
        Verilated::overWidthError("spi_miso");}
    if (VL_UNLIKELY((cmddata_valid & 0xfeU))) {
        Verilated::overWidthError("cmddata_valid");}
    if (VL_UNLIKELY((cmddata_payload_Bytenumber & 0xc0U))) {
        Verilated::overWidthError("cmddata_payload_Bytenumber");}
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
}
#endif  // VL_DEBUG
