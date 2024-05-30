// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vsrio_tt__Syms.h"


VL_ATTR_COLD void Vsrio_tt___024root__trace_init_sub__TOP__0(Vsrio_tt___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vsrio_tt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsrio_tt___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+328,"srio_clk", false,-1);
    tracep->declBit(c+329,"reset", false,-1);
    tracep->declBit(c+330,"iresp_stream_valid", false,-1);
    tracep->declBit(c+331,"iresp_stream_ready", false,-1);
    tracep->declQuad(c+332,"iresp_stream_payload", false,-1, 63,0);
    tracep->pushNamePrefix("srio_tt ");
    tracep->declBit(c+328,"srio_clk", false,-1);
    tracep->declBit(c+329,"reset", false,-1);
    tracep->declBit(c+330,"iresp_stream_valid", false,-1);
    tracep->declBit(c+331,"iresp_stream_ready", false,-1);
    tracep->declQuad(c+332,"iresp_stream_payload", false,-1, 63,0);
    tracep->declBus(c+344,"SrioFtype_NREAD", false,-1, 3,0);
    tracep->declBus(c+345,"SrioFtype_NWRITE", false,-1, 3,0);
    tracep->declBus(c+346,"SrioFtype_SWRITE", false,-1, 3,0);
    tracep->declBus(c+347,"SrioFtype_DOORB", false,-1, 3,0);
    tracep->declBus(c+348,"SrioFtype_MESSG", false,-1, 3,0);
    tracep->declBus(c+349,"SrioFtype_RESP", false,-1, 3,0);
    tracep->declBus(c+350,"SrioFtype_FTYPE9", false,-1, 3,0);
    tracep->declBus(c+351,"SrioTtype_TNWR", false,-1, 3,0);
    tracep->declBus(c+345,"SrioTtype_TNWR_R", false,-1, 3,0);
    tracep->declBus(c+352,"SrioTtype_TNDATA", false,-1, 3,0);
    tracep->declBus(c+353,"SrioTtype_TWDATA", false,-1, 3,0);
    tracep->declBit(c+10,"srio_area_srio_top_m_axis_ireq_tvalid", false,-1);
    tracep->declBit(c+11,"srio_area_srio_top_m_axis_ireq_tlast", false,-1);
    tracep->declQuad(c+248,"srio_area_srio_top_m_axis_ireq_tdata", false,-1, 63,0);
    tracep->declBus(c+354,"srio_area_srio_top_m_axis_ireq_tkeep", false,-1, 7,0);
    tracep->declBus(c+355,"srio_area_srio_top_m_axis_ireq_tuser", false,-1, 31,0);
    tracep->declBit(c+12,"srio_area_srio_top_s_axis_iresp_tready", false,-1);
    tracep->declBit(c+13,"srio_area_srio_top_m_axis_tresp_tvalid", false,-1);
    tracep->declBit(c+14,"srio_area_srio_top_m_axis_tresp_tlast", false,-1);
    tracep->declQuad(c+250,"srio_area_srio_top_m_axis_tresp_tdata", false,-1, 63,0);
    tracep->declBus(c+354,"srio_area_srio_top_m_axis_tresp_tkeep", false,-1, 7,0);
    tracep->declBus(c+356,"srio_area_srio_top_m_axis_tresp_tuser", false,-1, 31,0);
    tracep->declBit(c+357,"srio_area_srio_top_s_axis_treq_tready", false,-1);
    tracep->declBit(c+15,"srio_area_srio_top_s_axis_usercmd_tready", false,-1);
    tracep->declBit(c+16,"srio_area_srio_top_m_axis_rspstream_tvalid", false,-1);
    tracep->declQuad(c+1,"srio_area_srio_top_m_axis_rspstream_tdata", false,-1, 63,0);
    tracep->declQuad(c+17,"srio_area_srio_top_data_out_0", false,-1, 63,0);
    tracep->declQuad(c+19,"srio_area_srio_top_data_out_1", false,-1, 63,0);
    tracep->declQuad(c+21,"srio_area_srio_top_data_out_2", false,-1, 63,0);
    tracep->declQuad(c+23,"srio_area_srio_top_data_out_3", false,-1, 63,0);
    tracep->declQuad(c+25,"srio_area_srio_top_data_out_4", false,-1, 63,0);
    tracep->declQuad(c+27,"srio_area_srio_top_data_out_5", false,-1, 63,0);
    tracep->declQuad(c+29,"srio_area_srio_top_data_out_6", false,-1, 63,0);
    tracep->declQuad(c+31,"srio_area_srio_top_data_out_7", false,-1, 63,0);
    tracep->declQuad(c+33,"srio_area_srio_top_data_out_8", false,-1, 63,0);
    tracep->declQuad(c+35,"srio_area_srio_top_data_out_9", false,-1, 63,0);
    tracep->declQuad(c+37,"srio_area_srio_top_data_out_10", false,-1, 63,0);
    tracep->declQuad(c+39,"srio_area_srio_top_data_out_11", false,-1, 63,0);
    tracep->declQuad(c+41,"srio_area_srio_top_data_out_12", false,-1, 63,0);
    tracep->declQuad(c+43,"srio_area_srio_top_data_out_13", false,-1, 63,0);
    tracep->declQuad(c+45,"srio_area_srio_top_data_out_14", false,-1, 63,0);
    tracep->declQuad(c+47,"srio_area_srio_top_data_out_15", false,-1, 63,0);
    tracep->declBit(c+49,"srio_area_srio_top_busy", false,-1);
    tracep->declBus(c+3,"srio_area_srio_top_doorbell_info", false,-1, 15,0);
    tracep->declBit(c+50,"srio_area_srio_top_doorbell_intr", false,-1);
    tracep->declQuad(c+51,"srio_area_srio_test_usercmd_user_addr", false,-1, 33,0);
    tracep->declBus(c+292,"srio_area_srio_test_usercmd_user_ftype", false,-1, 3,0);
    tracep->declBus(c+293,"srio_area_srio_test_usercmd_user_ttype", false,-1, 3,0);
    tracep->declBus(c+294,"srio_area_srio_test_usercmd_user_size", false,-1, 7,0);
    tracep->declBus(c+295,"srio_area_srio_test_usercmd_user_prio", false,-1, 1,0);
    tracep->declBus(c+296,"srio_area_srio_test_usercmd_user_tid", false,-1, 7,0);
    tracep->declBit(c+53,"srio_area_srio_test_m_axis_usercmd_tvalid", false,-1);
    tracep->declQuad(c+54,"srio_area_srio_test_m_axis_usercmd_tdata", false,-1, 63,0);
    tracep->declBit(c+56,"srio_area_srio_test_send_start", false,-1);
    tracep->pushNamePrefix("srio_area_srio_test ");
    tracep->declBit(c+328,"srio_clk", false,-1);
    tracep->declBit(c+329,"reset", false,-1);
    tracep->declQuad(c+51,"usercmd_user_addr", false,-1, 33,0);
    tracep->declBus(c+292,"usercmd_user_ftype", false,-1, 3,0);
    tracep->declBus(c+293,"usercmd_user_ttype", false,-1, 3,0);
    tracep->declBus(c+294,"usercmd_user_size", false,-1, 7,0);
    tracep->declBus(c+295,"usercmd_user_prio", false,-1, 1,0);
    tracep->declBus(c+296,"usercmd_user_tid", false,-1, 7,0);
    tracep->declBit(c+53,"m_axis_usercmd_tvalid", false,-1);
    tracep->declBit(c+15,"m_axis_usercmd_tready", false,-1);
    tracep->declQuad(c+54,"m_axis_usercmd_tdata", false,-1, 63,0);
    tracep->declBit(c+56,"send_start", false,-1);
    tracep->declBus(c+344,"SrioFtype_NREAD", false,-1, 3,0);
    tracep->declBus(c+345,"SrioFtype_NWRITE", false,-1, 3,0);
    tracep->declBus(c+346,"SrioFtype_SWRITE", false,-1, 3,0);
    tracep->declBus(c+347,"SrioFtype_DOORB", false,-1, 3,0);
    tracep->declBus(c+348,"SrioFtype_MESSG", false,-1, 3,0);
    tracep->declBus(c+349,"SrioFtype_RESP", false,-1, 3,0);
    tracep->declBus(c+350,"SrioFtype_FTYPE9", false,-1, 3,0);
    tracep->declBus(c+351,"SrioTtype_TNWR", false,-1, 3,0);
    tracep->declBus(c+345,"SrioTtype_TNWR_R", false,-1, 3,0);
    tracep->declBus(c+352,"SrioTtype_TNDATA", false,-1, 3,0);
    tracep->declBus(c+353,"SrioTtype_TWDATA", false,-1, 3,0);
    tracep->declBus(c+352,"srio_area_fsm_enumDef_BOOT", false,-1, 3,0);
    tracep->declBus(c+358,"srio_area_fsm_enumDef_Init_Start", false,-1, 3,0);
    tracep->declBus(c+344,"srio_area_fsm_enumDef_Send_Read", false,-1, 3,0);
    tracep->declBus(c+359,"srio_area_fsm_enumDef_DoorBeel", false,-1, 3,0);
    tracep->declBus(c+351,"srio_area_fsm_enumDef_Send_DoorBeel", false,-1, 3,0);
    tracep->declBus(c+345,"srio_area_fsm_enumDef_Nwrite", false,-1, 3,0);
    tracep->declBus(c+346,"srio_area_fsm_enumDef_Send_Data", false,-1, 3,0);
    tracep->declBus(c+360,"srio_area_fsm_enumDef_Send_Stream", false,-1, 3,0);
    tracep->declBus(c+353,"srio_area_fsm_enumDef_Send_Nwrite", false,-1, 3,0);
    tracep->declBit(c+252,"srio_area_timer_io_clear", false,-1);
    tracep->declBit(c+316,"srio_area_timer_io_full", false,-1);
    tracep->declBus(c+253,"srio_area_timer_io_value", false,-1, 31,0);
    tracep->declBit(c+252,"when_Srio_Test_Top_l103", false,-1);
    tracep->declQuad(c+51,"srio_area_user_addr", false,-1, 33,0);
    tracep->declBus(c+292,"srio_area_user_ftype", false,-1, 3,0);
    tracep->declBus(c+293,"srio_area_user_ttype", false,-1, 3,0);
    tracep->declBus(c+294,"srio_area_user_size", false,-1, 7,0);
    tracep->declBus(c+295,"srio_area_user_prio", false,-1, 1,0);
    tracep->declBus(c+296,"srio_area_user_tid", false,-1, 7,0);
    tracep->declBit(c+53,"srio_area_user_valid", false,-1);
    tracep->declQuad(c+54,"srio_area_user_data", false,-1, 63,0);
    tracep->declBit(c+56,"srio_area_start", false,-1);
    tracep->declBit(c+361,"srio_area_fsm_wantExit", false,-1);
    tracep->declBit(c+317,"srio_area_fsm_wantStart", false,-1);
    tracep->declBit(c+361,"srio_area_fsm_wantKill", false,-1);
    tracep->declBus(c+57,"srio_area_fsm_counter", false,-1, 15,0);
    tracep->declBus(c+318,"srio_area_fsm_stateReg", false,-1, 3,0);
    tracep->declBus(c+319,"srio_area_fsm_stateNext", false,-1, 3,0);
    tracep->declBit(c+58,"when_Srio_Test_Top_l140", false,-1);
    tracep->declBit(c+59,"when_Srio_Test_Top_l163", false,-1);
    tracep->declBit(c+60,"when_Srio_Test_Top_l187", false,-1);
    tracep->declQuad(c+297,"usercmd_user_ftype_string", false,-1, 47,0);
    tracep->declQuad(c+299,"usercmd_user_ttype_string", false,-1, 47,0);
    tracep->declQuad(c+301,"srio_area_user_ftype_string", false,-1, 47,0);
    tracep->declQuad(c+303,"srio_area_user_ttype_string", false,-1, 47,0);
    tracep->declArray(c+320,"srio_area_fsm_stateReg_string", false,-1, 103,0);
    tracep->declArray(c+324,"srio_area_fsm_stateNext_string", false,-1, 103,0);
    tracep->pushNamePrefix("srio_area_timer ");
    tracep->declBit(c+357,"io_tick", false,-1);
    tracep->declBit(c+252,"io_clear", false,-1);
    tracep->declBus(c+362,"io_limit", false,-1, 31,0);
    tracep->declBit(c+316,"io_full", false,-1);
    tracep->declBus(c+253,"io_value", false,-1, 31,0);
    tracep->declBit(c+328,"srio_clk", false,-1);
    tracep->declBit(c+329,"reset", false,-1);
    tracep->declBus(c+253,"counter", false,-1, 31,0);
    tracep->declBit(c+254,"limitHit", false,-1);
    tracep->declBit(c+61,"inhibitFull", false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("srio_area_srio_top ");
    tracep->declBit(c+328,"srio_clk", false,-1);
    tracep->declBit(c+329,"reset", false,-1);
    tracep->declBit(c+10,"m_axis_ireq_tvalid", false,-1);
    tracep->declBit(c+357,"m_axis_ireq_tready", false,-1);
    tracep->declBit(c+11,"m_axis_ireq_tlast", false,-1);
    tracep->declQuad(c+248,"m_axis_ireq_tdata", false,-1, 63,0);
    tracep->declBus(c+354,"m_axis_ireq_tkeep", false,-1, 7,0);
    tracep->declBus(c+355,"m_axis_ireq_tuser", false,-1, 31,0);
    tracep->declBit(c+13,"s_axis_iresp_tvalid", false,-1);
    tracep->declBit(c+12,"s_axis_iresp_tready", false,-1);
    tracep->declBit(c+14,"s_axis_iresp_tlast", false,-1);
    tracep->declQuad(c+250,"s_axis_iresp_tdata", false,-1, 63,0);
    tracep->declBus(c+354,"s_axis_iresp_tkeep", false,-1, 7,0);
    tracep->declBus(c+356,"s_axis_iresp_tuser", false,-1, 31,0);
    tracep->declBit(c+13,"m_axis_tresp_tvalid", false,-1);
    tracep->declBit(c+12,"m_axis_tresp_tready", false,-1);
    tracep->declBit(c+14,"m_axis_tresp_tlast", false,-1);
    tracep->declQuad(c+250,"m_axis_tresp_tdata", false,-1, 63,0);
    tracep->declBus(c+354,"m_axis_tresp_tkeep", false,-1, 7,0);
    tracep->declBus(c+356,"m_axis_tresp_tuser", false,-1, 31,0);
    tracep->declBit(c+10,"s_axis_treq_tvalid", false,-1);
    tracep->declBit(c+357,"s_axis_treq_tready", false,-1);
    tracep->declBit(c+11,"s_axis_treq_tlast", false,-1);
    tracep->declQuad(c+248,"s_axis_treq_tdata", false,-1, 63,0);
    tracep->declBus(c+354,"s_axis_treq_tkeep", false,-1, 7,0);
    tracep->declBus(c+355,"s_axis_treq_tuser", false,-1, 31,0);
    tracep->declQuad(c+51,"usercmd_user_addr", false,-1, 33,0);
    tracep->declBus(c+292,"usercmd_user_ftype", false,-1, 3,0);
    tracep->declBus(c+293,"usercmd_user_ttype", false,-1, 3,0);
    tracep->declBus(c+294,"usercmd_user_size", false,-1, 7,0);
    tracep->declBus(c+295,"usercmd_user_prio", false,-1, 1,0);
    tracep->declBus(c+296,"usercmd_user_tid", false,-1, 7,0);
    tracep->declBit(c+53,"s_axis_usercmd_tvalid", false,-1);
    tracep->declBit(c+15,"s_axis_usercmd_tready", false,-1);
    tracep->declQuad(c+54,"s_axis_usercmd_tdata", false,-1, 63,0);
    tracep->declBit(c+56,"send_start", false,-1);
    tracep->declBit(c+16,"m_axis_rspstream_tvalid", false,-1);
    tracep->declBit(c+331,"m_axis_rspstream_tready", false,-1);
    tracep->declQuad(c+1,"m_axis_rspstream_tdata", false,-1, 63,0);
    tracep->declQuad(c+363,"data_in_0", false,-1, 63,0);
    tracep->declQuad(c+365,"data_in_1", false,-1, 63,0);
    tracep->declQuad(c+367,"data_in_2", false,-1, 63,0);
    tracep->declQuad(c+369,"data_in_3", false,-1, 63,0);
    tracep->declQuad(c+371,"data_in_4", false,-1, 63,0);
    tracep->declQuad(c+373,"data_in_5", false,-1, 63,0);
    tracep->declQuad(c+375,"data_in_6", false,-1, 63,0);
    tracep->declQuad(c+377,"data_in_7", false,-1, 63,0);
    tracep->declQuad(c+379,"data_in_8", false,-1, 63,0);
    tracep->declQuad(c+381,"data_in_9", false,-1, 63,0);
    tracep->declQuad(c+381,"data_in_10", false,-1, 63,0);
    tracep->declQuad(c+381,"data_in_11", false,-1, 63,0);
    tracep->declQuad(c+381,"data_in_12", false,-1, 63,0);
    tracep->declQuad(c+381,"data_in_13", false,-1, 63,0);
    tracep->declQuad(c+381,"data_in_14", false,-1, 63,0);
    tracep->declQuad(c+381,"data_in_15", false,-1, 63,0);
    tracep->declQuad(c+17,"data_out_0", false,-1, 63,0);
    tracep->declQuad(c+19,"data_out_1", false,-1, 63,0);
    tracep->declQuad(c+21,"data_out_2", false,-1, 63,0);
    tracep->declQuad(c+23,"data_out_3", false,-1, 63,0);
    tracep->declQuad(c+25,"data_out_4", false,-1, 63,0);
    tracep->declQuad(c+27,"data_out_5", false,-1, 63,0);
    tracep->declQuad(c+29,"data_out_6", false,-1, 63,0);
    tracep->declQuad(c+31,"data_out_7", false,-1, 63,0);
    tracep->declQuad(c+33,"data_out_8", false,-1, 63,0);
    tracep->declQuad(c+35,"data_out_9", false,-1, 63,0);
    tracep->declQuad(c+37,"data_out_10", false,-1, 63,0);
    tracep->declQuad(c+39,"data_out_11", false,-1, 63,0);
    tracep->declQuad(c+41,"data_out_12", false,-1, 63,0);
    tracep->declQuad(c+43,"data_out_13", false,-1, 63,0);
    tracep->declQuad(c+45,"data_out_14", false,-1, 63,0);
    tracep->declQuad(c+47,"data_out_15", false,-1, 63,0);
    tracep->declBit(c+49,"busy", false,-1);
    tracep->declBus(c+3,"doorbell_info", false,-1, 15,0);
    tracep->declBit(c+50,"doorbell_intr", false,-1);
    tracep->declBus(c+344,"SrioFtype_NREAD", false,-1, 3,0);
    tracep->declBus(c+345,"SrioFtype_NWRITE", false,-1, 3,0);
    tracep->declBus(c+346,"SrioFtype_SWRITE", false,-1, 3,0);
    tracep->declBus(c+347,"SrioFtype_DOORB", false,-1, 3,0);
    tracep->declBus(c+348,"SrioFtype_MESSG", false,-1, 3,0);
    tracep->declBus(c+349,"SrioFtype_RESP", false,-1, 3,0);
    tracep->declBus(c+350,"SrioFtype_FTYPE9", false,-1, 3,0);
    tracep->declBus(c+351,"SrioTtype_TNWR", false,-1, 3,0);
    tracep->declBus(c+345,"SrioTtype_TNWR_R", false,-1, 3,0);
    tracep->declBus(c+352,"SrioTtype_TNDATA", false,-1, 3,0);
    tracep->declBus(c+353,"SrioTtype_TWDATA", false,-1, 3,0);
    tracep->declQuad(c+62,"srio_area_srio_reg_simplebus_RDATA", false,-1, 63,0);
    tracep->declQuad(c+17,"srio_area_srio_reg_data_out_0", false,-1, 63,0);
    tracep->declQuad(c+19,"srio_area_srio_reg_data_out_1", false,-1, 63,0);
    tracep->declQuad(c+21,"srio_area_srio_reg_data_out_2", false,-1, 63,0);
    tracep->declQuad(c+23,"srio_area_srio_reg_data_out_3", false,-1, 63,0);
    tracep->declQuad(c+25,"srio_area_srio_reg_data_out_4", false,-1, 63,0);
    tracep->declQuad(c+27,"srio_area_srio_reg_data_out_5", false,-1, 63,0);
    tracep->declQuad(c+29,"srio_area_srio_reg_data_out_6", false,-1, 63,0);
    tracep->declQuad(c+31,"srio_area_srio_reg_data_out_7", false,-1, 63,0);
    tracep->declQuad(c+33,"srio_area_srio_reg_data_out_8", false,-1, 63,0);
    tracep->declQuad(c+35,"srio_area_srio_reg_data_out_9", false,-1, 63,0);
    tracep->declQuad(c+37,"srio_area_srio_reg_data_out_10", false,-1, 63,0);
    tracep->declQuad(c+39,"srio_area_srio_reg_data_out_11", false,-1, 63,0);
    tracep->declQuad(c+41,"srio_area_srio_reg_data_out_12", false,-1, 63,0);
    tracep->declQuad(c+43,"srio_area_srio_reg_data_out_13", false,-1, 63,0);
    tracep->declQuad(c+45,"srio_area_srio_reg_data_out_14", false,-1, 63,0);
    tracep->declQuad(c+47,"srio_area_srio_reg_data_out_15", false,-1, 63,0);
    tracep->declBit(c+64,"srio_area_target_m_axis_tresp_tvalid", false,-1);
    tracep->declBit(c+65,"srio_area_target_m_axis_tresp_tlast", false,-1);
    tracep->declQuad(c+4,"srio_area_target_m_axis_tresp_tdata", false,-1, 63,0);
    tracep->declBus(c+354,"srio_area_target_m_axis_tresp_tkeep", false,-1, 7,0);
    tracep->declBus(c+356,"srio_area_target_m_axis_tresp_tuser", false,-1, 31,0);
    tracep->declBit(c+357,"srio_area_target_s_axis_treq_tready", false,-1);
    tracep->declBus(c+66,"srio_area_target_simplebus_WADDR", false,-1, 8,0);
    tracep->declQuad(c+248,"srio_area_target_simplebus_WDATA", false,-1, 63,0);
    tracep->declBit(c+67,"srio_area_target_simplebus_WENABLE", false,-1);
    tracep->declBus(c+68,"srio_area_target_simplebus_RADDR", false,-1, 8,0);
    tracep->declBit(c+357,"srio_area_target_simplebus_RENABLE", false,-1);
}

VL_ATTR_COLD void Vsrio_tt___024root__trace_init_sub__TOP__1(Vsrio_tt___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vsrio_tt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsrio_tt___024root__trace_init_sub__TOP__1\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+3,"srio_area_target_doorbell_info", false,-1, 15,0);
    tracep->declBit(c+50,"srio_area_target_doorbell_intr", false,-1);
    tracep->declBit(c+49,"srio_area_target_busy", false,-1);
    tracep->declBit(c+69,"srio_area_target_fifo_io_push_ready", false,-1);
    tracep->declBit(c+13,"srio_area_target_fifo_io_pop_valid", false,-1);
    tracep->declQuad(c+250,"srio_area_target_fifo_io_pop_payload", false,-1, 63,0);
    tracep->declBus(c+70,"srio_area_target_fifo_io_occupancy", false,-1, 8,0);
    tracep->declBus(c+71,"srio_area_target_fifo_io_availability", false,-1, 8,0);
    tracep->declBit(c+72,"srio_area_streamfifo_io_push_ready", false,-1);
    tracep->declBit(c+10,"srio_area_streamfifo_io_pop_valid", false,-1);
    tracep->declQuad(c+248,"srio_area_streamfifo_io_pop_payload", false,-1, 63,0);
    tracep->declBus(c+73,"srio_area_streamfifo_io_occupancy", false,-1, 8,0);
    tracep->declBus(c+74,"srio_area_streamfifo_io_availability", false,-1, 8,0);
    tracep->declBit(c+278,"srio_area_intitaor_m_axis_ireq_tvalid", false,-1);
    tracep->declBit(c+75,"srio_area_intitaor_m_axis_ireq_tlast", false,-1);
    tracep->declQuad(c+6,"srio_area_intitaor_m_axis_ireq_tdata", false,-1, 63,0);
    tracep->declBus(c+354,"srio_area_intitaor_m_axis_ireq_tkeep", false,-1, 7,0);
    tracep->declBus(c+355,"srio_area_intitaor_m_axis_ireq_tuser", false,-1, 31,0);
    tracep->declBit(c+12,"srio_area_intitaor_s_axis_iresp_tready", false,-1);
    tracep->declBit(c+15,"srio_area_intitaor_usercmd_user_data_ready", false,-1);
    tracep->declBit(c+16,"srio_area_intitaor_iresp_stream_valid", false,-1);
    tracep->declQuad(c+1,"srio_area_intitaor_iresp_stream_payload", false,-1, 63,0);
    tracep->declBit(c+76,"srio_area_intitaor_rsp_received", false,-1);
    tracep->declBit(c+77,"srio_area_intitaor_request_autocheck_error", false,-1);
    tracep->declBit(c+78,"srio_target_target_resp_stream_fire", false,-1);
    tracep->declBit(c+10,"srio_intiator_intiator_req_stream_fire", false,-1);
    tracep->declQuad(c+305,"usercmd_user_ftype_string", false,-1, 47,0);
    tracep->declQuad(c+307,"usercmd_user_ttype_string", false,-1, 47,0);
    tracep->pushNamePrefix("srio_area_intitaor ");
    tracep->declBit(c+278,"m_axis_ireq_tvalid", false,-1);
    tracep->declBit(c+357,"m_axis_ireq_tready", false,-1);
    tracep->declBit(c+75,"m_axis_ireq_tlast", false,-1);
    tracep->declQuad(c+6,"m_axis_ireq_tdata", false,-1, 63,0);
    tracep->declBus(c+354,"m_axis_ireq_tkeep", false,-1, 7,0);
    tracep->declBus(c+355,"m_axis_ireq_tuser", false,-1, 31,0);
    tracep->declBit(c+13,"s_axis_iresp_tvalid", false,-1);
    tracep->declBit(c+12,"s_axis_iresp_tready", false,-1);
    tracep->declBit(c+14,"s_axis_iresp_tlast", false,-1);
    tracep->declQuad(c+250,"s_axis_iresp_tdata", false,-1, 63,0);
    tracep->declBus(c+354,"s_axis_iresp_tkeep", false,-1, 7,0);
    tracep->declBus(c+356,"s_axis_iresp_tuser", false,-1, 31,0);
    tracep->declQuad(c+51,"usercmd_user_addr", false,-1, 33,0);
    tracep->declBus(c+292,"usercmd_user_ftype", false,-1, 3,0);
    tracep->declBus(c+293,"usercmd_user_ttype", false,-1, 3,0);
    tracep->declBus(c+294,"usercmd_user_size", false,-1, 7,0);
    tracep->declBus(c+295,"usercmd_user_prio", false,-1, 1,0);
    tracep->declBus(c+296,"usercmd_user_tid", false,-1, 7,0);
    tracep->declBit(c+53,"usercmd_user_data_valid", false,-1);
    tracep->declBit(c+15,"usercmd_user_data_ready", false,-1);
    tracep->declQuad(c+54,"usercmd_user_data_payload", false,-1, 63,0);
    tracep->declBit(c+56,"send_start", false,-1);
    tracep->declBit(c+16,"iresp_stream_valid", false,-1);
    tracep->declBit(c+331,"iresp_stream_ready", false,-1);
    tracep->declQuad(c+1,"iresp_stream_payload", false,-1, 63,0);
    tracep->declBit(c+76,"rsp_received", false,-1);
    tracep->declBit(c+77,"request_autocheck_error", false,-1);
    tracep->declBit(c+328,"srio_clk", false,-1);
    tracep->declBit(c+329,"reset", false,-1);
    tracep->declBus(c+344,"SrioFtype_NREAD", false,-1, 3,0);
    tracep->declBus(c+345,"SrioFtype_NWRITE", false,-1, 3,0);
    tracep->declBus(c+346,"SrioFtype_SWRITE", false,-1, 3,0);
    tracep->declBus(c+347,"SrioFtype_DOORB", false,-1, 3,0);
    tracep->declBus(c+348,"SrioFtype_MESSG", false,-1, 3,0);
    tracep->declBus(c+349,"SrioFtype_RESP", false,-1, 3,0);
    tracep->declBus(c+350,"SrioFtype_FTYPE9", false,-1, 3,0);
    tracep->declBus(c+351,"SrioTtype_TNWR", false,-1, 3,0);
    tracep->declBus(c+345,"SrioTtype_TNWR_R", false,-1, 3,0);
    tracep->declBus(c+352,"SrioTtype_TNDATA", false,-1, 3,0);
    tracep->declBus(c+353,"SrioTtype_TWDATA", false,-1, 3,0);
    tracep->declBit(c+79,"fifo_io_push_valid", false,-1);
    tracep->declBit(c+15,"streamfifo_4_io_push_ready", false,-1);
    tracep->declBit(c+80,"streamfifo_4_io_pop_valid", false,-1);
    tracep->declQuad(c+8,"streamfifo_4_io_pop_payload", false,-1, 63,0);
    tracep->declBus(c+81,"streamfifo_4_io_occupancy", false,-1, 8,0);
    tracep->declBus(c+82,"streamfifo_4_io_availability", false,-1, 8,0);
    tracep->declBit(c+12,"fifo_io_push_ready", false,-1);
    tracep->declBit(c+16,"fifo_io_pop_valid", false,-1);
    tracep->declQuad(c+1,"fifo_io_pop_payload", false,-1, 63,0);
    tracep->declBus(c+83,"fifo_io_occupancy", false,-1, 8,0);
    tracep->declBus(c+84,"fifo_io_availability", false,-1, 8,0);
    tracep->declQuad(c+334,"header_beat", false,-1, 63,0);
    tracep->declBus(c+279,"current_beat_cnt", false,-1, 5,0);
    tracep->declBit(c+278,"intiator_intiator_req_stream_fire", false,-1);
    tracep->declBit(c+243,"when_Intitaor_l37", false,-1);
    tracep->declBit(c+278,"intiator_intiator_req_stream_fire_1", false,-1);
    tracep->declBus(c+309,"number_of_data_beats", false,-1, 4,0);
    tracep->declBit(c+75,"ireq_tlast", false,-1);
    tracep->declBit(c+336,"when_Intitaor_l49", false,-1);
    tracep->declBit(c+278,"intiator_intiator_req_stream_fire_2", false,-1);
    tracep->declBit(c+278,"intiator_intiator_req_stream_fire_3", false,-1);
    tracep->declBit(c+337,"when_Intitaor_l51", false,-1);
    tracep->declBit(c+361,"when_Intitaor_l53", false,-1);
    tracep->declBit(c+357,"when_Intitaor_l55", false,-1);
    tracep->declQuad(c+6,"ireq_tdata", false,-1, 63,0);
    tracep->declBit(c+278,"intiator_intiator_req_stream_fire_4", false,-1);
    tracep->declBit(c+280,"when_Intitaor_l63", false,-1);
    tracep->declBit(c+85,"user_data_ready", false,-1);
    tracep->declBit(c+278,"ireq_tvalid", false,-1);
    tracep->declBit(c+86,"send_start_d", false,-1);
    tracep->declBit(c+278,"intiator_intiator_req_stream_fire_5", false,-1);
    tracep->declBit(c+281,"when_Intitaor_l73", false,-1);
    tracep->declBit(c+87,"when_Intitaor_l76", false,-1);
    tracep->declBit(c+278,"intiator_intiator_req_stream_fire_6", false,-1);
    tracep->declQuad(c+310,"write_queue_data_d", false,-1, 63,0);
    tracep->declQuad(c+255,"write_queue_data", false,-1, 63,0);
    tracep->declBit(c+282,"expecting_a_response", false,-1);
    tracep->declBit(c+278,"intiator_intiator_req_stream_fire_7", false,-1);
    tracep->declBit(c+283,"when_Intitaor_l91", false,-1);
    tracep->declQuad(c+257,"read_queue_data", false,-1, 63,0);
    tracep->declBus(c+259,"expected_tid", false,-1, 7,0);
    tracep->declBus(c+260,"expected_ftype", false,-1, 3,0);
    tracep->declBus(c+261,"expected_size", false,-1, 7,0);
    tracep->declBit(c+88,"compare_received", false,-1);
    tracep->declBit(c+78,"intiator_intiator_resp_stream_fire", false,-1);
    tracep->declBit(c+76,"when_Intitaor_l106", false,-1);
    tracep->declBit(c+78,"intiator_intiator_resp_stream_fire_1", false,-1);
    tracep->declBit(c+78,"intiator_intiator_resp_stream_fire_2", false,-1);
    tracep->declBit(c+77,"request_autocheck_error_1", false,-1);
    tracep->declBit(c+78,"intiator_intiator_resp_stream_fire_3", false,-1);
    tracep->declBit(c+89,"when_Intitaor_l117", false,-1);
    tracep->declBit(c+90,"nread_iresp_write", false,-1);
    tracep->declBit(c+78,"intiator_intiator_resp_stream_fire_4", false,-1);
    tracep->declBit(c+338,"when_Intitaor_l137", false,-1);
    tracep->declBit(c+78,"intiator_intiator_resp_stream_fire_5", false,-1);
    tracep->declBit(c+76,"when_Intitaor_l139", false,-1);
    tracep->declBit(c+78,"intiator_intiator_resp_stream_fire_6", false,-1);
    tracep->declQuad(c+312,"usercmd_user_ftype_string", false,-1, 47,0);
    tracep->declQuad(c+314,"usercmd_user_ttype_string", false,-1, 47,0);
    tracep->pushNamePrefix("fifo ");
    tracep->declBit(c+79,"io_push_valid", false,-1);
    tracep->declBit(c+12,"io_push_ready", false,-1);
    tracep->declQuad(c+250,"io_push_payload", false,-1, 63,0);
    tracep->declBit(c+16,"io_pop_valid", false,-1);
    tracep->declBit(c+331,"io_pop_ready", false,-1);
    tracep->declQuad(c+1,"io_pop_payload", false,-1, 63,0);
    tracep->declBit(c+361,"io_flush", false,-1);
    tracep->declBus(c+83,"io_occupancy", false,-1, 8,0);
    tracep->declBus(c+84,"io_availability", false,-1, 8,0);
    tracep->declBit(c+328,"srio_clk", false,-1);
    tracep->declBit(c+329,"reset", false,-1);
    tracep->declBit(c+91,"logic_pushPtr_willIncrement", false,-1);
    tracep->declBit(c+361,"logic_pushPtr_willClear", false,-1);
    tracep->declBus(c+92,"logic_pushPtr_valueNext", false,-1, 7,0);
    tracep->declBus(c+93,"logic_pushPtr_value", false,-1, 7,0);
    tracep->declBit(c+94,"logic_pushPtr_willOverflowIfInc", false,-1);
    tracep->declBit(c+95,"logic_pushPtr_willOverflow", false,-1);
    tracep->declBit(c+275,"logic_popPtr_willIncrement", false,-1);
    tracep->declBit(c+361,"logic_popPtr_willClear", false,-1);
    tracep->declBus(c+276,"logic_popPtr_valueNext", false,-1, 7,0);
    tracep->declBus(c+96,"logic_popPtr_value", false,-1, 7,0);
    tracep->declBit(c+97,"logic_popPtr_willOverflowIfInc", false,-1);
    tracep->declBit(c+339,"logic_popPtr_willOverflow", false,-1);
    tracep->declBit(c+98,"logic_ptrMatch", false,-1);
    tracep->declBit(c+99,"logic_risingOccupancy", false,-1);
    tracep->declBit(c+100,"logic_pushing", false,-1);
    tracep->declBit(c+277,"logic_popping", false,-1);
    tracep->declBit(c+101,"logic_empty", false,-1);
    tracep->declBit(c+102,"logic_full", false,-1);
    tracep->declBit(c+340,"when_Stream_l1101", false,-1);
    tracep->declBus(c+103,"logic_ptrDif", false,-1, 7,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("streamfifo_4 ");
    tracep->declBit(c+53,"io_push_valid", false,-1);
    tracep->declBit(c+15,"io_push_ready", false,-1);
    tracep->declQuad(c+54,"io_push_payload", false,-1, 63,0);
    tracep->declBit(c+80,"io_pop_valid", false,-1);
    tracep->declBit(c+278,"io_pop_ready", false,-1);
    tracep->declQuad(c+8,"io_pop_payload", false,-1, 63,0);
    tracep->declBit(c+361,"io_flush", false,-1);
    tracep->declBus(c+81,"io_occupancy", false,-1, 8,0);
    tracep->declBus(c+82,"io_availability", false,-1, 8,0);
    tracep->declBit(c+328,"srio_clk", false,-1);
    tracep->declBit(c+329,"reset", false,-1);
    tracep->declBit(c+104,"logic_pushPtr_willIncrement", false,-1);
    tracep->declBit(c+361,"logic_pushPtr_willClear", false,-1);
    tracep->declBus(c+105,"logic_pushPtr_valueNext", false,-1, 7,0);
    tracep->declBus(c+106,"logic_pushPtr_value", false,-1, 7,0);
    tracep->declBit(c+107,"logic_pushPtr_willOverflowIfInc", false,-1);
    tracep->declBit(c+108,"logic_pushPtr_willOverflow", false,-1);
    tracep->declBit(c+284,"logic_popPtr_willIncrement", false,-1);
    tracep->declBit(c+361,"logic_popPtr_willClear", false,-1);
    tracep->declBus(c+285,"logic_popPtr_valueNext", false,-1, 7,0);
    tracep->declBus(c+109,"logic_popPtr_value", false,-1, 7,0);
    tracep->declBit(c+110,"logic_popPtr_willOverflowIfInc", false,-1);
    tracep->declBit(c+244,"logic_popPtr_willOverflow", false,-1);
    tracep->declBit(c+111,"logic_ptrMatch", false,-1);
    tracep->declBit(c+112,"logic_risingOccupancy", false,-1);
    tracep->declBit(c+113,"logic_pushing", false,-1);
    tracep->declBit(c+286,"logic_popping", false,-1);
    tracep->declBit(c+114,"logic_empty", false,-1);
    tracep->declBit(c+115,"logic_full", false,-1);
    tracep->declBit(c+245,"when_Stream_l1101", false,-1);
    tracep->declBus(c+116,"logic_ptrDif", false,-1, 7,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("srio_area_srio_reg ");
    tracep->declBus(c+68,"simplebus_RADDR", false,-1, 8,0);
    tracep->declQuad(c+62,"simplebus_RDATA", false,-1, 63,0);
    tracep->declBit(c+357,"simplebus_RENABLE", false,-1);
    tracep->declBus(c+66,"simplebus_WADDR", false,-1, 8,0);
    tracep->declQuad(c+248,"simplebus_WDATA", false,-1, 63,0);
    tracep->declBit(c+67,"simplebus_WENABLE", false,-1);
    tracep->declQuad(c+363,"data_in_0", false,-1, 63,0);
    tracep->declQuad(c+365,"data_in_1", false,-1, 63,0);
    tracep->declQuad(c+367,"data_in_2", false,-1, 63,0);
    tracep->declQuad(c+369,"data_in_3", false,-1, 63,0);
    tracep->declQuad(c+371,"data_in_4", false,-1, 63,0);
    tracep->declQuad(c+373,"data_in_5", false,-1, 63,0);
    tracep->declQuad(c+375,"data_in_6", false,-1, 63,0);
    tracep->declQuad(c+377,"data_in_7", false,-1, 63,0);
    tracep->declQuad(c+379,"data_in_8", false,-1, 63,0);
    tracep->declQuad(c+381,"data_in_9", false,-1, 63,0);
    tracep->declQuad(c+381,"data_in_10", false,-1, 63,0);
    tracep->declQuad(c+381,"data_in_11", false,-1, 63,0);
    tracep->declQuad(c+381,"data_in_12", false,-1, 63,0);
    tracep->declQuad(c+381,"data_in_13", false,-1, 63,0);
    tracep->declQuad(c+381,"data_in_14", false,-1, 63,0);
    tracep->declQuad(c+381,"data_in_15", false,-1, 63,0);
    tracep->declQuad(c+17,"data_out_0", false,-1, 63,0);
    tracep->declQuad(c+19,"data_out_1", false,-1, 63,0);
    tracep->declQuad(c+21,"data_out_2", false,-1, 63,0);
    tracep->declQuad(c+23,"data_out_3", false,-1, 63,0);
    tracep->declQuad(c+25,"data_out_4", false,-1, 63,0);
    tracep->declQuad(c+27,"data_out_5", false,-1, 63,0);
    tracep->declQuad(c+29,"data_out_6", false,-1, 63,0);
    tracep->declQuad(c+31,"data_out_7", false,-1, 63,0);
    tracep->declQuad(c+33,"data_out_8", false,-1, 63,0);
    tracep->declQuad(c+35,"data_out_9", false,-1, 63,0);
    tracep->declQuad(c+37,"data_out_10", false,-1, 63,0);
    tracep->declQuad(c+39,"data_out_11", false,-1, 63,0);
    tracep->declQuad(c+41,"data_out_12", false,-1, 63,0);
    tracep->declQuad(c+43,"data_out_13", false,-1, 63,0);
    tracep->declQuad(c+45,"data_out_14", false,-1, 63,0);
    tracep->declQuad(c+47,"data_out_15", false,-1, 63,0);
    tracep->declBit(c+328,"srio_clk", false,-1);
    tracep->declBit(c+329,"reset", false,-1);
    tracep->declBit(c+117,"busslave_readError", false,-1);
    tracep->declQuad(c+62,"busslave_readData", false,-1, 63,0);
    tracep->declBit(c+118,"read_hit_0x0000", false,-1);
    tracep->declBit(c+119,"write_hit_0x0000", false,-1);
    tracep->declQuad(c+383,"Version", false,-1, 63,0);
    tracep->declBit(c+120,"read_hit_0x0008", false,-1);
}

VL_ATTR_COLD void Vsrio_tt___024root__trace_init_sub__TOP__2(Vsrio_tt___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vsrio_tt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsrio_tt___024root__trace_init_sub__TOP__2\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+121,"write_hit_0x0008", false,-1);
    tracep->declBit(c+122,"read_hit_0x0010", false,-1);
    tracep->declBit(c+123,"write_hit_0x0010", false,-1);
    tracep->declBit(c+124,"read_hit_0x0018", false,-1);
    tracep->declBit(c+125,"write_hit_0x0018", false,-1);
    tracep->declBit(c+126,"read_hit_0x0020", false,-1);
    tracep->declBit(c+127,"write_hit_0x0020", false,-1);
    tracep->declBit(c+128,"read_hit_0x0028", false,-1);
    tracep->declBit(c+129,"write_hit_0x0028", false,-1);
    tracep->declBit(c+130,"read_hit_0x0030", false,-1);
    tracep->declBit(c+131,"write_hit_0x0030", false,-1);
    tracep->declBit(c+132,"read_hit_0x0038", false,-1);
    tracep->declBit(c+133,"write_hit_0x0038", false,-1);
    tracep->declBit(c+134,"read_hit_0x0040", false,-1);
    tracep->declBit(c+135,"write_hit_0x0040", false,-1);
    tracep->declBit(c+136,"read_hit_0x0048", false,-1);
    tracep->declBit(c+137,"write_hit_0x0048", false,-1);
    tracep->declBit(c+138,"read_hit_0x0050", false,-1);
    tracep->declBit(c+139,"write_hit_0x0050", false,-1);
    tracep->declBit(c+140,"read_hit_0x0058", false,-1);
    tracep->declBit(c+141,"write_hit_0x0058", false,-1);
    tracep->declBit(c+142,"read_hit_0x0060", false,-1);
    tracep->declBit(c+143,"write_hit_0x0060", false,-1);
    tracep->declBit(c+144,"read_hit_0x0068", false,-1);
    tracep->declBit(c+145,"write_hit_0x0068", false,-1);
    tracep->declBit(c+146,"read_hit_0x0070", false,-1);
    tracep->declBit(c+147,"write_hit_0x0070", false,-1);
    tracep->declBit(c+148,"read_hit_0x0078", false,-1);
    tracep->declBit(c+149,"write_hit_0x0078", false,-1);
    tracep->declBit(c+150,"read_hit_0x0080", false,-1);
    tracep->declBit(c+151,"write_hit_0x0080", false,-1);
    tracep->declBit(c+152,"read_hit_0x0088", false,-1);
    tracep->declBit(c+153,"write_hit_0x0088", false,-1);
    tracep->declBit(c+154,"read_hit_0x0090", false,-1);
    tracep->declBit(c+155,"write_hit_0x0090", false,-1);
    tracep->declBit(c+156,"read_hit_0x0098", false,-1);
    tracep->declBit(c+157,"write_hit_0x0098", false,-1);
    tracep->declBit(c+158,"read_hit_0x00a0", false,-1);
    tracep->declBit(c+159,"write_hit_0x00a0", false,-1);
    tracep->declBit(c+160,"read_hit_0x00a8", false,-1);
    tracep->declBit(c+161,"write_hit_0x00a8", false,-1);
    tracep->declBit(c+162,"read_hit_0x00b0", false,-1);
    tracep->declBit(c+163,"write_hit_0x00b0", false,-1);
    tracep->declBit(c+164,"read_hit_0x00b8", false,-1);
    tracep->declBit(c+165,"write_hit_0x00b8", false,-1);
    tracep->declBit(c+166,"read_hit_0x00c0", false,-1);
    tracep->declBit(c+167,"write_hit_0x00c0", false,-1);
    tracep->declBit(c+168,"read_hit_0x00c8", false,-1);
    tracep->declBit(c+169,"write_hit_0x00c8", false,-1);
    tracep->declBit(c+170,"read_hit_0x00d0", false,-1);
    tracep->declBit(c+171,"write_hit_0x00d0", false,-1);
    tracep->declBit(c+172,"read_hit_0x00d8", false,-1);
    tracep->declBit(c+173,"write_hit_0x00d8", false,-1);
    tracep->declBit(c+174,"read_hit_0x00e0", false,-1);
    tracep->declBit(c+175,"write_hit_0x00e0", false,-1);
    tracep->declBit(c+176,"read_hit_0x00e8", false,-1);
    tracep->declBit(c+177,"write_hit_0x00e8", false,-1);
    tracep->declBit(c+178,"read_hit_0x00f0", false,-1);
    tracep->declBit(c+179,"write_hit_0x00f0", false,-1);
    tracep->declBit(c+180,"read_hit_0x00f8", false,-1);
    tracep->declBit(c+181,"write_hit_0x00f8", false,-1);
    tracep->declBit(c+182,"read_hit_0x0100", false,-1);
    tracep->declBit(c+183,"write_hit_0x0100", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("srio_area_streamfifo ");
    tracep->declBit(c+278,"io_push_valid", false,-1);
    tracep->declBit(c+72,"io_push_ready", false,-1);
    tracep->declQuad(c+6,"io_push_payload", false,-1, 63,0);
    tracep->declBit(c+10,"io_pop_valid", false,-1);
    tracep->declBit(c+357,"io_pop_ready", false,-1);
    tracep->declQuad(c+248,"io_pop_payload", false,-1, 63,0);
    tracep->declBit(c+361,"io_flush", false,-1);
    tracep->declBus(c+73,"io_occupancy", false,-1, 8,0);
    tracep->declBus(c+74,"io_availability", false,-1, 8,0);
    tracep->declBit(c+328,"srio_clk", false,-1);
    tracep->declBit(c+329,"reset", false,-1);
    tracep->declBit(c+287,"logic_pushPtr_willIncrement", false,-1);
    tracep->declBit(c+361,"logic_pushPtr_willClear", false,-1);
    tracep->declBus(c+288,"logic_pushPtr_valueNext", false,-1, 7,0);
    tracep->declBus(c+184,"logic_pushPtr_value", false,-1, 7,0);
    tracep->declBit(c+185,"logic_pushPtr_willOverflowIfInc", false,-1);
    tracep->declBit(c+246,"logic_pushPtr_willOverflow", false,-1);
    tracep->declBit(c+186,"logic_popPtr_willIncrement", false,-1);
    tracep->declBit(c+361,"logic_popPtr_willClear", false,-1);
    tracep->declBus(c+289,"logic_popPtr_valueNext", false,-1, 7,0);
    tracep->declBus(c+187,"logic_popPtr_value", false,-1, 7,0);
    tracep->declBit(c+188,"logic_popPtr_willOverflowIfInc", false,-1);
    tracep->declBit(c+189,"logic_popPtr_willOverflow", false,-1);
    tracep->declBit(c+190,"logic_ptrMatch", false,-1);
    tracep->declBit(c+191,"logic_risingOccupancy", false,-1);
    tracep->declBit(c+290,"logic_pushing", false,-1);
    tracep->declBit(c+10,"logic_popping", false,-1);
    tracep->declBit(c+192,"logic_empty", false,-1);
    tracep->declBit(c+193,"logic_full", false,-1);
    tracep->declBit(c+247,"when_Stream_l1101", false,-1);
    tracep->declBus(c+194,"logic_ptrDif", false,-1, 7,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("srio_area_target ");
    tracep->declBit(c+64,"m_axis_tresp_tvalid", false,-1);
    tracep->declBit(c+357,"m_axis_tresp_tready", false,-1);
    tracep->declBit(c+65,"m_axis_tresp_tlast", false,-1);
    tracep->declQuad(c+4,"m_axis_tresp_tdata", false,-1, 63,0);
    tracep->declBus(c+354,"m_axis_tresp_tkeep", false,-1, 7,0);
    tracep->declBus(c+356,"m_axis_tresp_tuser", false,-1, 31,0);
    tracep->declBit(c+10,"s_axis_treq_tvalid", false,-1);
    tracep->declBit(c+357,"s_axis_treq_tready", false,-1);
    tracep->declBit(c+11,"s_axis_treq_tlast", false,-1);
    tracep->declQuad(c+248,"s_axis_treq_tdata", false,-1, 63,0);
    tracep->declBus(c+354,"s_axis_treq_tkeep", false,-1, 7,0);
    tracep->declBus(c+355,"s_axis_treq_tuser", false,-1, 31,0);
    tracep->declBus(c+68,"simplebus_RADDR", false,-1, 8,0);
    tracep->declQuad(c+62,"simplebus_RDATA", false,-1, 63,0);
    tracep->declBit(c+357,"simplebus_RENABLE", false,-1);
    tracep->declBus(c+66,"simplebus_WADDR", false,-1, 8,0);
    tracep->declQuad(c+248,"simplebus_WDATA", false,-1, 63,0);
    tracep->declBit(c+67,"simplebus_WENABLE", false,-1);
    tracep->declBus(c+3,"doorbell_info", false,-1, 15,0);
    tracep->declBit(c+50,"doorbell_intr", false,-1);
    tracep->declBit(c+49,"busy", false,-1);
    tracep->declBit(c+328,"srio_clk", false,-1);
    tracep->declBit(c+329,"reset", false,-1);
    tracep->declBus(c+344,"SrioFtype_NREAD", false,-1, 3,0);
    tracep->declBus(c+345,"SrioFtype_NWRITE", false,-1, 3,0);
    tracep->declBus(c+346,"SrioFtype_SWRITE", false,-1, 3,0);
    tracep->declBus(c+347,"SrioFtype_DOORB", false,-1, 3,0);
    tracep->declBus(c+348,"SrioFtype_MESSG", false,-1, 3,0);
    tracep->declBus(c+349,"SrioFtype_RESP", false,-1, 3,0);
    tracep->declBus(c+350,"SrioFtype_FTYPE9", false,-1, 3,0);
    tracep->declBus(c+351,"SrioTtype_TNWR", false,-1, 3,0);
    tracep->declBus(c+345,"SrioTtype_TNWR_R", false,-1, 3,0);
    tracep->declBus(c+352,"SrioTtype_TNDATA", false,-1, 3,0);
    tracep->declBus(c+353,"SrioTtype_TWDATA", false,-1, 3,0);
    tracep->declBit(c+361,"busy_1", false,-1);
    tracep->declBit(c+50,"doorbell_intr_1", false,-1);
    tracep->declBus(c+262,"current_tid", false,-1, 7,0);
    tracep->declBus(c+263,"current_ftype", false,-1, 3,0);
    tracep->declBus(c+264,"current_ttype", false,-1, 3,0);
    tracep->declBus(c+265,"current_size", false,-1, 7,0);
    tracep->declBus(c+266,"current_prio", false,-1, 1,0);
    tracep->declQuad(c+267,"current_addr", false,-1, 33,0);
    tracep->declBus(c+385,"current_srcid", false,-1, 15,0);
    tracep->declQuad(c+269,"response_data_in_d", false,-1, 47,0);
    tracep->declQuad(c+271,"response_data_in", false,-1, 47,0);
    tracep->declBus(c+273,"doorbell_info_d", false,-1, 15,0);
    tracep->declBit(c+10,"target_target_req_stream_fire", false,-1);
    tracep->declBit(c+341,"when_Target_l32", false,-1);
    tracep->declBus(c+3,"doorbell_info_1", false,-1, 15,0);
    tracep->declBit(c+10,"target_target_req_stream_fire_1", false,-1);
    tracep->declBit(c+195,"first_beat", false,-1);
    tracep->declBit(c+10,"target_target_req_stream_fire_2", false,-1);
    tracep->declBit(c+196,"when_Target_l40", false,-1);
    tracep->declBit(c+10,"target_target_req_stream_fire_3", false,-1);
    tracep->declBit(c+197,"generate_a_response", false,-1);
    tracep->declBit(c+10,"target_target_req_stream_fire_4", false,-1);
    tracep->declBit(c+342,"when_Target_l49", false,-1);
    tracep->declBit(c+198,"capture_data", false,-1);
    tracep->declBit(c+10,"target_target_req_stream_fire_5", false,-1);
    tracep->declBit(c+199,"when_Target_l59", false,-1);
    tracep->declBit(c+10,"target_target_req_stream_fire_6", false,-1);
    tracep->declBit(c+196,"when_Target_l61", false,-1);
    tracep->declBit(c+10,"target_target_req_stream_fire_7", false,-1);
    tracep->declBit(c+67,"data_store_wen", false,-1);
    tracep->declBus(c+66,"data_store_waddr", false,-1, 8,0);
    tracep->declBit(c+10,"target_target_req_stream_fire_8", false,-1);
    tracep->declBit(c+199,"when_Target_l70", false,-1);
    tracep->declBit(c+10,"target_target_req_stream_fire_9", false,-1);
    tracep->declQuad(c+200,"response_data_out_d", false,-1, 47,0);
    tracep->declQuad(c+202,"response_data_out", false,-1, 47,0);
    tracep->declBus(c+204,"response_tid", false,-1, 7,0);
    tracep->declBus(c+205,"response_ftype", false,-1, 3,0);
    tracep->declBus(c+206,"response_size", false,-1, 7,0);
    tracep->declBus(c+207,"response_prio", false,-1, 1,0);
    tracep->declBus(c+208,"starting_read_addr", false,-1, 8,0);
    tracep->declBit(c+209,"pull_from_store", false,-1);
    tracep->declBus(c+210,"responding_ttype", false,-1, 3,0);
    tracep->declBus(c+211,"current_beat_cnt", false,-1, 5,0);
    tracep->declBus(c+274,"number_of_data_beats", false,-1, 5,0);
    tracep->declBit(c+212,"when_Target_l95", false,-1);
    tracep->declBit(c+64,"target_target_resp_stream_fire", false,-1);
    tracep->declBit(c+213,"when_Target_l101", false,-1);
    tracep->declBit(c+64,"target_target_resp_stream_fire_1", false,-1);
    tracep->declBit(c+65,"tresp_tlast", false,-1);
    tracep->declBit(c+214,"when_Target_l110", false,-1);
    tracep->declBit(c+64,"target_target_resp_stream_fire_2", false,-1);
    tracep->declBit(c+64,"target_target_resp_stream_fire_3", false,-1);
    tracep->declBit(c+343,"when_Target_l112", false,-1);
    tracep->declBit(c+357,"when_Target_l114", false,-1);
    tracep->declBit(c+215,"generate_rsp", false,-1);
    tracep->declBit(c+216,"generate_rsp_d", false,-1);
    tracep->declBit(c+49,"pull_from_store_d", false,-1);
    tracep->declBit(c+217,"when_Target_l125", false,-1);
    tracep->declBus(c+68,"data_store_raddr", false,-1, 8,0);
    tracep->declBit(c+218,"when_Target_l136", false,-1);
    tracep->declBit(c+64,"target_target_resp_stream_fire_4", false,-1);
    tracep->declBit(c+219,"when_Target_l138", false,-1);
    tracep->declBit(c+64,"tresp_tvalid", false,-1);
    tracep->declBit(c+218,"when_Target_l145", false,-1);
    tracep->declBit(c+64,"target_target_resp_stream_fire_5", false,-1);
    tracep->declBit(c+213,"when_Target_l147", false,-1);
    tracep->declQuad(c+220,"header_beat", false,-1, 63,0);
    tracep->declQuad(c+4,"tresp_tdata", false,-1, 63,0);
    tracep->declQuad(c+386,"data_store_dout", false,-1, 63,0);
    tracep->declBit(c+64,"target_target_resp_stream_fire_6", false,-1);
    tracep->declBit(c+222,"when_Target_l169", false,-1);
    tracep->declBit(c+64,"target_target_resp_stream_fire_7", false,-1);
    tracep->declBit(c+223,"when_Target_l171", false,-1);
    tracep->declQuad(c+224,"responding_ttype_string", false,-1, 47,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("srio_area_target_fifo ");
    tracep->declBit(c+64,"io_push_valid", false,-1);
    tracep->declBit(c+69,"io_push_ready", false,-1);
    tracep->declQuad(c+4,"io_push_payload", false,-1, 63,0);
    tracep->declBit(c+13,"io_pop_valid", false,-1);
    tracep->declBit(c+12,"io_pop_ready", false,-1);
    tracep->declQuad(c+250,"io_pop_payload", false,-1, 63,0);
    tracep->declBit(c+361,"io_flush", false,-1);
    tracep->declBus(c+70,"io_occupancy", false,-1, 8,0);
    tracep->declBus(c+71,"io_availability", false,-1, 8,0);
    tracep->declBit(c+328,"srio_clk", false,-1);
    tracep->declBit(c+329,"reset", false,-1);
    tracep->declBit(c+226,"logic_pushPtr_willIncrement", false,-1);
    tracep->declBit(c+361,"logic_pushPtr_willClear", false,-1);
    tracep->declBus(c+227,"logic_pushPtr_valueNext", false,-1, 7,0);
    tracep->declBus(c+228,"logic_pushPtr_value", false,-1, 7,0);
    tracep->declBit(c+229,"logic_pushPtr_willOverflowIfInc", false,-1);
    tracep->declBit(c+230,"logic_pushPtr_willOverflow", false,-1);
    tracep->declBit(c+231,"logic_popPtr_willIncrement", false,-1);
    tracep->declBit(c+361,"logic_popPtr_willClear", false,-1);
    tracep->declBus(c+291,"logic_popPtr_valueNext", false,-1, 7,0);
    tracep->declBus(c+232,"logic_popPtr_value", false,-1, 7,0);
    tracep->declBit(c+233,"logic_popPtr_willOverflowIfInc", false,-1);
    tracep->declBit(c+234,"logic_popPtr_willOverflow", false,-1);
    tracep->declBit(c+235,"logic_ptrMatch", false,-1);
    tracep->declBit(c+236,"logic_risingOccupancy", false,-1);
}

VL_ATTR_COLD void Vsrio_tt___024root__trace_init_sub__TOP__3(Vsrio_tt___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vsrio_tt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsrio_tt___024root__trace_init_sub__TOP__3\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+237,"logic_pushing", false,-1);
    tracep->declBit(c+238,"logic_popping", false,-1);
    tracep->declBit(c+239,"logic_empty", false,-1);
    tracep->declBit(c+240,"logic_full", false,-1);
    tracep->declBit(c+241,"when_Stream_l1101", false,-1);
    tracep->declBus(c+242,"logic_ptrDif", false,-1, 7,0);
    tracep->popNamePrefix(3);
}

VL_ATTR_COLD void Vsrio_tt___024root__trace_init_top(Vsrio_tt___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vsrio_tt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsrio_tt___024root__trace_init_top\n"); );
    // Body
    Vsrio_tt___024root__trace_init_sub__TOP__0(vlSelf, tracep);
    Vsrio_tt___024root__trace_init_sub__TOP__1(vlSelf, tracep);
    Vsrio_tt___024root__trace_init_sub__TOP__2(vlSelf, tracep);
    Vsrio_tt___024root__trace_init_sub__TOP__3(vlSelf, tracep);
}

VL_ATTR_COLD void Vsrio_tt___024root__trace_full_top_0(void* voidSelf, VerilatedVcd* tracep);
void Vsrio_tt___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd* tracep);
void Vsrio_tt___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vsrio_tt___024root__trace_register(Vsrio_tt___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vsrio_tt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsrio_tt___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vsrio_tt___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vsrio_tt___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vsrio_tt___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vsrio_tt___024root__trace_full_sub_0(Vsrio_tt___024root* vlSelf, VerilatedVcd* tracep);
VL_ATTR_COLD void Vsrio_tt___024root__trace_full_sub_1(Vsrio_tt___024root* vlSelf, VerilatedVcd* tracep);
VL_ATTR_COLD void Vsrio_tt___024root__trace_full_sub_2(Vsrio_tt___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vsrio_tt___024root__trace_full_top_0(void* voidSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsrio_tt___024root__trace_full_top_0\n"); );
    // Init
    Vsrio_tt___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vsrio_tt___024root*>(voidSelf);
    Vsrio_tt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vsrio_tt___024root__trace_full_sub_0((&vlSymsp->TOP), tracep);
    Vsrio_tt___024root__trace_full_sub_1((&vlSymsp->TOP), tracep);
    Vsrio_tt___024root__trace_full_sub_2((&vlSymsp->TOP), tracep);
}

VL_ATTR_COLD void Vsrio_tt___024root__trace_full_sub_0(Vsrio_tt___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vsrio_tt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsrio_tt___024root__trace_full_sub_0\n"); );
    // Init
    vluint32_t* const oldp VL_ATTR_UNUSED = tracep->oldp(vlSymsp->__Vm_baseCode);
    // Body
    tracep->fullQData(oldp+1,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT___zz_logic_ram_port0),64);
    tracep->fullSData(oldp+3,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__doorbell_info_1),16);
    tracep->fullQData(oldp+4,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__tresp_tdata),64);
    tracep->fullQData(oldp+6,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__ireq_tdata),64);
    tracep->fullQData(oldp+8,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT___zz_logic_ram_port0),64);
    tracep->fullBit(oldp+10,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo_io_pop_valid));
    tracep->fullBit(oldp+11,(vlSelf->srio_tt__DOT__srio_area_srio_top_m_axis_ireq_tlast));
    tracep->fullBit(oldp+12,((1U & (~ (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_full)))));
    tracep->fullBit(oldp+13,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo_io_pop_valid));
    tracep->fullBit(oldp+14,(vlSelf->srio_tt__DOT__srio_area_srio_top_m_axis_tresp_tlast));
    tracep->fullBit(oldp+15,((1U & (~ (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_full)))));
    tracep->fullBit(oldp+16,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo_io_pop_valid));
    tracep->fullQData(oldp+17,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_0),64);
    tracep->fullQData(oldp+19,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_1),64);
    tracep->fullQData(oldp+21,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_2),64);
    tracep->fullQData(oldp+23,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_3),64);
    tracep->fullQData(oldp+25,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_4),64);
    tracep->fullQData(oldp+27,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_5),64);
    tracep->fullQData(oldp+29,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_6),64);
    tracep->fullQData(oldp+31,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_7),64);
    tracep->fullQData(oldp+33,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_8),64);
    tracep->fullQData(oldp+35,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_9),64);
    tracep->fullQData(oldp+37,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_10),64);
    tracep->fullQData(oldp+39,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_11),64);
    tracep->fullQData(oldp+41,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_12),64);
    tracep->fullQData(oldp+43,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_13),64);
    tracep->fullQData(oldp+45,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_14),64);
    tracep->fullQData(oldp+47,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_15),64);
    tracep->fullBit(oldp+49,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__pull_from_store_d));
    tracep->fullBit(oldp+50,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__doorbell_intr_1));
    tracep->fullQData(oldp+51,(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_addr),34);
    tracep->fullBit(oldp+53,(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_valid));
    tracep->fullQData(oldp+54,(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_data),64);
    tracep->fullBit(oldp+56,(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_start));
    tracep->fullSData(oldp+57,(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_fsm_counter),16);
    tracep->fullBit(oldp+58,((0x190U < (IData)(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_fsm_counter))));
    tracep->fullBit(oldp+59,((0xc8U < (IData)(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_fsm_counter))));
    tracep->fullBit(oldp+60,((0xeU < (IData)(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_fsm_counter))));
    tracep->fullBit(oldp+61,(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_timer__DOT__inhibitFull));
    tracep->fullQData(oldp+62,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT__busslave_readData),64);
    tracep->fullBit(oldp+64,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__tresp_tvalid));
    tracep->fullBit(oldp+65,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__tresp_tlast));
    tracep->fullSData(oldp+66,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_waddr),9);
    tracep->fullBit(oldp+67,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_wen));
    tracep->fullSData(oldp+68,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr),9);
    tracep->fullBit(oldp+69,((1U & (~ (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_full)))));
    tracep->fullSData(oldp+70,(((((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_risingOccupancy) 
                                  & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_ptrMatch)) 
                                 << 8U) | (0xffU & 
                                           ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_pushPtr_value) 
                                            - (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_popPtr_value))))),9);
    tracep->fullSData(oldp+71,(((((~ (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_risingOccupancy)) 
                                  & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_ptrMatch)) 
                                 << 8U) | (0xffU & 
                                           ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_popPtr_value) 
                                            - (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_pushPtr_value))))),9);
    tracep->fullBit(oldp+72,((1U & (~ (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_full)))));
    tracep->fullSData(oldp+73,(((((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_risingOccupancy) 
                                  & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_ptrMatch)) 
                                 << 8U) | (0xffU & 
                                           ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_pushPtr_value) 
                                            - (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_popPtr_value))))),9);
    tracep->fullSData(oldp+74,(((((~ (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_risingOccupancy)) 
                                  & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_ptrMatch)) 
                                 << 8U) | (0xffU & 
                                           ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_popPtr_value) 
                                            - (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_pushPtr_value))))),9);
    tracep->fullBit(oldp+75,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__ireq_tlast));
    tracep->fullBit(oldp+76,((((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo_io_pop_valid) 
                               & (~ (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_full))) 
                              & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top_m_axis_tresp_tlast))));
    tracep->fullBit(oldp+77,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__request_autocheck_error_1));
    tracep->fullBit(oldp+78,(((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo_io_pop_valid) 
                              & (~ (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_full)))));
    tracep->fullBit(oldp+79,(((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__nread_iresp_write) 
                              & ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo_io_pop_valid) 
                                 & (~ (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_full))))));
    tracep->fullBit(oldp+80,((1U & ((~ ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_ptrMatch) 
                                        & (~ (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_risingOccupancy)))) 
                                    & (~ ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT___zz_io_pop_valid) 
                                          & (~ (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_full))))))));
    tracep->fullSData(oldp+81,(((((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_risingOccupancy) 
                                  & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_ptrMatch)) 
                                 << 8U) | (0xffU & 
                                           ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_pushPtr_value) 
                                            - (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_popPtr_value))))),9);
    tracep->fullSData(oldp+82,(((((~ (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_risingOccupancy)) 
                                  & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_ptrMatch)) 
                                 << 8U) | (0xffU & 
                                           ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_popPtr_value) 
                                            - (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_pushPtr_value))))),9);
    tracep->fullSData(oldp+83,(((((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_risingOccupancy) 
                                  & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_ptrMatch)) 
                                 << 8U) | (0xffU & 
                                           ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_pushPtr_value) 
                                            - (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_popPtr_value))))),9);
    tracep->fullSData(oldp+84,(((((~ (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_risingOccupancy)) 
                                  & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_ptrMatch)) 
                                 << 8U) | (0xffU & 
                                           ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_popPtr_value) 
                                            - (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_pushPtr_value))))),9);
    tracep->fullBit(oldp+85,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__user_data_ready));
    tracep->fullBit(oldp+86,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__send_start_d));
    tracep->fullBit(oldp+87,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__when_Intitaor_l76));
    tracep->fullBit(oldp+88,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__compare_received));
    tracep->fullBit(oldp+89,(((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__compare_received) 
                              & ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo_io_pop_valid) 
                                 & (~ (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_full))))));
    tracep->fullBit(oldp+90,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__nread_iresp_write));
    tracep->fullBit(oldp+91,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_pushPtr_willIncrement));
    tracep->fullCData(oldp+92,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_pushPtr_valueNext),8);
    tracep->fullCData(oldp+93,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_pushPtr_value),8);
    tracep->fullBit(oldp+94,((0xffU == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_pushPtr_value))));
    tracep->fullBit(oldp+95,(((0xffU == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_pushPtr_value)) 
                              & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_pushPtr_willIncrement))));
    tracep->fullCData(oldp+96,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_popPtr_value),8);
    tracep->fullBit(oldp+97,((0xffU == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_popPtr_value))));
    tracep->fullBit(oldp+98,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_ptrMatch));
    tracep->fullBit(oldp+99,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_risingOccupancy));
    tracep->fullBit(oldp+100,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_pushing));
    tracep->fullBit(oldp+101,(((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_ptrMatch) 
                               & (~ (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_risingOccupancy)))));
    tracep->fullBit(oldp+102,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_full));
    tracep->fullCData(oldp+103,((0xffU & ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_pushPtr_value) 
                                          - (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_popPtr_value)))),8);
    tracep->fullBit(oldp+104,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_pushPtr_willIncrement));
    tracep->fullCData(oldp+105,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_pushPtr_valueNext),8);
    tracep->fullCData(oldp+106,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_pushPtr_value),8);
    tracep->fullBit(oldp+107,((0xffU == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_pushPtr_value))));
    tracep->fullBit(oldp+108,(((0xffU == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_pushPtr_value)) 
                               & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_pushPtr_willIncrement))));
    tracep->fullCData(oldp+109,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_popPtr_value),8);
    tracep->fullBit(oldp+110,((0xffU == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_popPtr_value))));
    tracep->fullBit(oldp+111,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_ptrMatch));
    tracep->fullBit(oldp+112,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_risingOccupancy));
    tracep->fullBit(oldp+113,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_pushing));
    tracep->fullBit(oldp+114,(((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_ptrMatch) 
                               & (~ (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_risingOccupancy)))));
    tracep->fullBit(oldp+115,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_full));
    tracep->fullCData(oldp+116,((0xffU & ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_pushPtr_value) 
                                          - (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_popPtr_value)))),8);
    tracep->fullBit(oldp+117,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT__busslave_readError));
    tracep->fullBit(oldp+118,((0U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))));
    tracep->fullBit(oldp+119,(((0U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_waddr)) 
                               & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_wen))));
    tracep->fullBit(oldp+120,((8U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))));
    tracep->fullBit(oldp+121,(((8U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_waddr)) 
                               & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_wen))));
    tracep->fullBit(oldp+122,((0x10U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))));
    tracep->fullBit(oldp+123,(((0x10U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_waddr)) 
                               & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_wen))));
    tracep->fullBit(oldp+124,((0x18U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))));
    tracep->fullBit(oldp+125,(((0x18U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_waddr)) 
                               & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_wen))));
    tracep->fullBit(oldp+126,((0x20U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))));
    tracep->fullBit(oldp+127,(((0x20U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_waddr)) 
                               & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_wen))));
    tracep->fullBit(oldp+128,((0x28U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))));
    tracep->fullBit(oldp+129,(((0x28U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_waddr)) 
                               & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_wen))));
    tracep->fullBit(oldp+130,((0x30U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))));
    tracep->fullBit(oldp+131,(((0x30U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_waddr)) 
                               & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_wen))));
    tracep->fullBit(oldp+132,((0x38U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))));
    tracep->fullBit(oldp+133,(((0x38U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_waddr)) 
                               & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_wen))));
    tracep->fullBit(oldp+134,((0x40U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))));
    tracep->fullBit(oldp+135,(((0x40U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_waddr)) 
                               & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_wen))));
    tracep->fullBit(oldp+136,((0x48U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))));
    tracep->fullBit(oldp+137,(((0x48U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_waddr)) 
                               & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_wen))));
    tracep->fullBit(oldp+138,((0x50U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))));
    tracep->fullBit(oldp+139,(((0x50U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_waddr)) 
                               & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_wen))));
    tracep->fullBit(oldp+140,((0x58U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))));
    tracep->fullBit(oldp+141,(((0x58U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_waddr)) 
                               & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_wen))));
    tracep->fullBit(oldp+142,((0x60U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))));
    tracep->fullBit(oldp+143,(((0x60U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_waddr)) 
                               & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_wen))));
    tracep->fullBit(oldp+144,((0x68U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))));
    tracep->fullBit(oldp+145,(((0x68U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_waddr)) 
                               & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_wen))));
    tracep->fullBit(oldp+146,((0x70U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))));
    tracep->fullBit(oldp+147,(((0x70U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_waddr)) 
                               & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_wen))));
    tracep->fullBit(oldp+148,((0x78U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))));
    tracep->fullBit(oldp+149,(((0x78U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_waddr)) 
                               & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_wen))));
    tracep->fullBit(oldp+150,((0x80U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))));
    tracep->fullBit(oldp+151,(((0x80U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_waddr)) 
                               & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_wen))));
    tracep->fullBit(oldp+152,((0x88U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))));
    tracep->fullBit(oldp+153,(((0x88U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_waddr)) 
                               & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_wen))));
    tracep->fullBit(oldp+154,((0x90U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))));
    tracep->fullBit(oldp+155,(((0x90U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_waddr)) 
                               & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_wen))));
    tracep->fullBit(oldp+156,((0x98U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))));
    tracep->fullBit(oldp+157,(((0x98U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_waddr)) 
                               & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_wen))));
}

VL_ATTR_COLD void Vsrio_tt___024root__trace_full_sub_1(Vsrio_tt___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vsrio_tt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsrio_tt___024root__trace_full_sub_1\n"); );
    // Init
    vluint32_t* const oldp VL_ATTR_UNUSED = tracep->oldp(vlSymsp->__Vm_baseCode);
    // Body
    tracep->fullBit(oldp+158,((0xa0U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))));
    tracep->fullBit(oldp+159,(((0xa0U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_waddr)) 
                               & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_wen))));
    tracep->fullBit(oldp+160,((0xa8U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))));
    tracep->fullBit(oldp+161,(((0xa8U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_waddr)) 
                               & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_wen))));
    tracep->fullBit(oldp+162,((0xb0U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))));
    tracep->fullBit(oldp+163,(((0xb0U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_waddr)) 
                               & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_wen))));
    tracep->fullBit(oldp+164,((0xb8U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))));
    tracep->fullBit(oldp+165,(((0xb8U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_waddr)) 
                               & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_wen))));
    tracep->fullBit(oldp+166,((0xc0U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))));
    tracep->fullBit(oldp+167,(((0xc0U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_waddr)) 
                               & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_wen))));
    tracep->fullBit(oldp+168,((0xc8U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))));
    tracep->fullBit(oldp+169,(((0xc8U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_waddr)) 
                               & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_wen))));
    tracep->fullBit(oldp+170,((0xd0U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))));
    tracep->fullBit(oldp+171,(((0xd0U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_waddr)) 
                               & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_wen))));
    tracep->fullBit(oldp+172,((0xd8U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))));
    tracep->fullBit(oldp+173,(((0xd8U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_waddr)) 
                               & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_wen))));
    tracep->fullBit(oldp+174,((0xe0U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))));
    tracep->fullBit(oldp+175,(((0xe0U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_waddr)) 
                               & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_wen))));
    tracep->fullBit(oldp+176,((0xe8U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))));
    tracep->fullBit(oldp+177,(((0xe8U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_waddr)) 
                               & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_wen))));
    tracep->fullBit(oldp+178,((0xf0U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))));
    tracep->fullBit(oldp+179,(((0xf0U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_waddr)) 
                               & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_wen))));
    tracep->fullBit(oldp+180,((0xf8U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))));
    tracep->fullBit(oldp+181,(((0xf8U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_waddr)) 
                               & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_wen))));
    tracep->fullBit(oldp+182,((0x100U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))));
    tracep->fullBit(oldp+183,(((0x100U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_waddr)) 
                               & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_wen))));
    tracep->fullCData(oldp+184,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_pushPtr_value),8);
    tracep->fullBit(oldp+185,((0xffU == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_pushPtr_value))));
    tracep->fullBit(oldp+186,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_popPtr_willIncrement));
    tracep->fullCData(oldp+187,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_popPtr_value),8);
    tracep->fullBit(oldp+188,((0xffU == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_popPtr_value))));
    tracep->fullBit(oldp+189,(((0xffU == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_popPtr_value)) 
                               & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_popPtr_willIncrement))));
    tracep->fullBit(oldp+190,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_ptrMatch));
    tracep->fullBit(oldp+191,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_risingOccupancy));
    tracep->fullBit(oldp+192,(((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_ptrMatch) 
                               & (~ (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_risingOccupancy)))));
    tracep->fullBit(oldp+193,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_full));
    tracep->fullCData(oldp+194,((0xffU & ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_pushPtr_value) 
                                          - (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_popPtr_value)))),8);
    tracep->fullBit(oldp+195,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__first_beat));
    tracep->fullBit(oldp+196,(((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo_io_pop_valid) 
                               & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top_m_axis_ireq_tlast))));
    tracep->fullBit(oldp+197,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__generate_a_response));
    tracep->fullBit(oldp+198,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__capture_data));
    tracep->fullBit(oldp+199,(((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__first_beat) 
                               & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo_io_pop_valid))));
    tracep->fullQData(oldp+200,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__response_data_out_d),48);
    tracep->fullQData(oldp+202,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__response_data_out),48);
    tracep->fullCData(oldp+204,((0xffU & (IData)((vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__response_data_out 
                                                  >> 0xcU)))),8);
    tracep->fullCData(oldp+205,((0xfU & (IData)((vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__response_data_out 
                                                 >> 8U)))),4);
    tracep->fullCData(oldp+206,((0xffU & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__response_data_out))),8);
    tracep->fullCData(oldp+207,((3U & (IData)((vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__response_data_out 
                                               >> 0x14U)))),2);
    tracep->fullSData(oldp+208,((0x1ffU & (IData)((vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__response_data_out 
                                                   >> 0x16U)))),9);
    tracep->fullBit(oldp+209,((IData)((0x80000200ULL 
                                       == (0x80000f00ULL 
                                           & vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__response_data_out)))));
    tracep->fullCData(oldp+210,(((2U == (0xfU & (IData)(
                                                        (vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__response_data_out 
                                                         >> 8U))))
                                  ? 8U : 0U)),4);
    tracep->fullCData(oldp+211,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__current_beat_cnt),6);
    tracep->fullBit(oldp+212,((0U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__current_beat_cnt))));
    tracep->fullBit(oldp+213,(((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__tresp_tvalid) 
                               & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__tresp_tlast))));
    tracep->fullBit(oldp+214,((0U == ((2U == (0xfU 
                                              & (IData)(
                                                        (vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__response_data_out 
                                                         >> 8U))))
                                       ? 8U : 0U))));
    tracep->fullBit(oldp+215,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__generate_rsp));
    tracep->fullBit(oldp+216,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__generate_rsp_d));
    tracep->fullBit(oldp+217,(((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__generate_rsp_d) 
                               & (0U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__current_beat_cnt)))));
    tracep->fullBit(oldp+218,(((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__pull_from_store_d) 
                               & (0U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__current_beat_cnt)))));
    tracep->fullBit(oldp+219,(((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__pull_from_store_d) 
                               & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__tresp_tvalid))));
    tracep->fullQData(oldp+220,((0xd0000000000000ULL 
                                 | (((QData)((IData)(
                                                     (0xffU 
                                                      & (IData)(
                                                                (vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__response_data_out 
                                                                 >> 0xcU))))) 
                                     << 0x38U) | (((QData)((IData)(
                                                                   ((2U 
                                                                     == 
                                                                     (0xfU 
                                                                      & (IData)(
                                                                                (vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__response_data_out 
                                                                                >> 8U))))
                                                                     ? 8U
                                                                     : 0U))) 
                                                   << 0x30U) 
                                                  | ((QData)((IData)(
                                                                     (3U 
                                                                      & (IData)(
                                                                                (vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__response_data_out 
                                                                                >> 0x14U))))) 
                                                     << 0x2dU))))),64);
    tracep->fullBit(oldp+222,(((0U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__current_beat_cnt)) 
                               & (~ (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__tresp_tvalid)))));
    tracep->fullBit(oldp+223,(((IData)((0x80000200ULL 
                                        == (0x80000f00ULL 
                                            & vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__response_data_out))) 
                               & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__tresp_tvalid))));
    tracep->fullQData(oldp+224,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__responding_ttype_string),48);
    tracep->fullBit(oldp+226,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_pushPtr_willIncrement));
    tracep->fullCData(oldp+227,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_pushPtr_valueNext),8);
    tracep->fullCData(oldp+228,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_pushPtr_value),8);
    tracep->fullBit(oldp+229,((0xffU == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_pushPtr_value))));
    tracep->fullBit(oldp+230,(((0xffU == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_pushPtr_value)) 
                               & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_pushPtr_willIncrement))));
    tracep->fullBit(oldp+231,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_popPtr_willIncrement));
    tracep->fullCData(oldp+232,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_popPtr_value),8);
    tracep->fullBit(oldp+233,((0xffU == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_popPtr_value))));
    tracep->fullBit(oldp+234,(((0xffU == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_popPtr_value)) 
                               & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_popPtr_willIncrement))));
    tracep->fullBit(oldp+235,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_ptrMatch));
    tracep->fullBit(oldp+236,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_risingOccupancy));
    tracep->fullBit(oldp+237,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_pushing));
    tracep->fullBit(oldp+238,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_popping));
    tracep->fullBit(oldp+239,(((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_ptrMatch) 
                               & (~ (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_risingOccupancy)))));
    tracep->fullBit(oldp+240,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_full));
    tracep->fullBit(oldp+241,(((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_pushing) 
                               != (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_popping))));
    tracep->fullCData(oldp+242,((0xffU & ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_pushPtr_value) 
                                          - (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_popPtr_value)))),8);
    tracep->fullBit(oldp+243,(((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__ireq_tvalid) 
                               & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__ireq_tlast))));
    tracep->fullBit(oldp+244,(((0xffU == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_popPtr_value)) 
                               & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_popPtr_willIncrement))));
    tracep->fullBit(oldp+245,(((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_pushing) 
                               != (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_popping))));
    tracep->fullBit(oldp+246,(((0xffU == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_pushPtr_value)) 
                               & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_pushPtr_willIncrement))));
    tracep->fullBit(oldp+247,(((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_pushing) 
                               != (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo_io_pop_valid))));
    tracep->fullQData(oldp+248,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT___zz_logic_ram_port0),64);
    tracep->fullQData(oldp+250,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT___zz_logic_ram_port0),64);
    tracep->fullBit(oldp+252,((0x7d0U <= vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_timer__DOT__counter)));
    tracep->fullIData(oldp+253,(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_timer__DOT__counter),32);
    tracep->fullBit(oldp+254,((0x7d0U == vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_timer__DOT__counter)));
    tracep->fullQData(oldp+255,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__write_queue_data),64);
    tracep->fullQData(oldp+257,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__read_queue_data),64);
    tracep->fullCData(oldp+259,((0xffU & (IData)((vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__read_queue_data 
                                                  >> 0xcU)))),8);
    tracep->fullCData(oldp+260,((0xfU & (IData)((vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__read_queue_data 
                                                 >> 8U)))),4);
    tracep->fullCData(oldp+261,((0xffU & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__read_queue_data))),8);
    tracep->fullCData(oldp+262,((0xffU & (IData)((vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT___zz_logic_ram_port0 
                                                  >> 0x38U)))),8);
    tracep->fullCData(oldp+263,((0xfU & (IData)((vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT___zz_logic_ram_port0 
                                                 >> 0x34U)))),4);
    tracep->fullCData(oldp+264,((0xfU & (IData)((vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT___zz_logic_ram_port0 
                                                 >> 0x30U)))),4);
    tracep->fullCData(oldp+265,((0xffU & (IData)((vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT___zz_logic_ram_port0 
                                                  >> 0x24U)))),8);
    tracep->fullCData(oldp+266,((3U & ((IData)(1U) 
                                       + (IData)((vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT___zz_logic_ram_port0 
                                                  >> 0x2dU))))),2);
    tracep->fullQData(oldp+267,((0x3ffffffffULL & vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT___zz_logic_ram_port0)),34);
    tracep->fullQData(oldp+269,((0xff00000000ULL | (QData)((IData)(
                                                                   (((0x12U 
                                                                      == 
                                                                      (0xffU 
                                                                       & (IData)(
                                                                                (vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT___zz_logic_ram_port0 
                                                                                >> 0x10U)))) 
                                                                     << 0x1fU) 
                                                                    | ((0x7fc00000U 
                                                                        & ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT___zz_logic_ram_port0) 
                                                                           << 0x16U)) 
                                                                       | ((0x300000U 
                                                                           & (((IData)(1U) 
                                                                               + (IData)(
                                                                                (vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT___zz_logic_ram_port0 
                                                                                >> 0x2dU))) 
                                                                              << 0x14U)) 
                                                                          | ((0xff000U 
                                                                              & ((IData)(
                                                                                (vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT___zz_logic_ram_port0 
                                                                                >> 0x38U)) 
                                                                                << 0xcU)) 
                                                                             | ((0xf00U 
                                                                                & ((IData)(
                                                                                (vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT___zz_logic_ram_port0 
                                                                                >> 0x34U)) 
                                                                                << 8U)) 
                                                                                | (0xffU 
                                                                                & (IData)(
                                                                                (vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT___zz_logic_ram_port0 
                                                                                >> 0x24U)))))))))))),48);
    tracep->fullQData(oldp+271,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__response_data_in),48);
    tracep->fullSData(oldp+273,((0xffffU & (IData)(
                                                   (vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT___zz_logic_ram_port0 
                                                    >> 0x10U)))),16);
}

VL_ATTR_COLD void Vsrio_tt___024root__trace_full_sub_2(Vsrio_tt___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vsrio_tt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsrio_tt___024root__trace_full_sub_2\n"); );
    // Init
    vluint32_t* const oldp VL_ATTR_UNUSED = tracep->oldp(vlSymsp->__Vm_baseCode);
    // Body
    tracep->fullCData(oldp+274,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__number_of_data_beats),6);
    tracep->fullBit(oldp+275,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_popPtr_willIncrement));
    tracep->fullCData(oldp+276,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_popPtr_valueNext),8);
    tracep->fullBit(oldp+277,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_popping));
    tracep->fullBit(oldp+278,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__ireq_tvalid));
    tracep->fullCData(oldp+279,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__current_beat_cnt),6);
    tracep->fullBit(oldp+280,(((0U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__current_beat_cnt)) 
                               & (~ (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__ireq_tvalid)))));
    tracep->fullBit(oldp+281,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__when_Intitaor_l73));
    tracep->fullBit(oldp+282,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__expecting_a_response));
    tracep->fullBit(oldp+283,(((0U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__current_beat_cnt)) 
                               & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__ireq_tvalid))));
    tracep->fullBit(oldp+284,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_popPtr_willIncrement));
    tracep->fullCData(oldp+285,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_popPtr_valueNext),8);
    tracep->fullBit(oldp+286,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_popping));
    tracep->fullBit(oldp+287,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_pushPtr_willIncrement));
    tracep->fullCData(oldp+288,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_pushPtr_valueNext),8);
    tracep->fullCData(oldp+289,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_popPtr_valueNext),8);
    tracep->fullBit(oldp+290,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_pushing));
    tracep->fullCData(oldp+291,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_popPtr_valueNext),8);
    tracep->fullCData(oldp+292,(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_ftype),4);
    tracep->fullCData(oldp+293,(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_ttype),4);
    tracep->fullCData(oldp+294,(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_size),8);
    tracep->fullCData(oldp+295,(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_prio),2);
    tracep->fullCData(oldp+296,(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_tid),8);
    tracep->fullQData(oldp+297,(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__usercmd_user_ftype_string),48);
    tracep->fullQData(oldp+299,(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__usercmd_user_ttype_string),48);
    tracep->fullQData(oldp+301,(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_ftype_string),48);
    tracep->fullQData(oldp+303,(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_ttype_string),48);
    tracep->fullQData(oldp+305,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__usercmd_user_ftype_string),48);
    tracep->fullQData(oldp+307,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__usercmd_user_ttype_string),48);
    tracep->fullCData(oldp+309,((0x1fU & ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_size) 
                                          >> 3U))),5);
    tracep->fullQData(oldp+310,((((QData)((IData)(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_tid)) 
                                  << 0xcU) | (QData)((IData)(
                                                             (((IData)(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_ftype) 
                                                               << 8U) 
                                                              | (IData)(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_size)))))),64);
    tracep->fullQData(oldp+312,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__usercmd_user_ftype_string),48);
    tracep->fullQData(oldp+314,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__usercmd_user_ttype_string),48);
    tracep->fullBit(oldp+316,(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_timer_io_full));
    tracep->fullBit(oldp+317,(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_fsm_wantStart));
    tracep->fullCData(oldp+318,(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_fsm_stateReg),4);
    tracep->fullCData(oldp+319,(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_fsm_stateNext),4);
    tracep->fullWData(oldp+320,(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_fsm_stateReg_string),104);
    tracep->fullWData(oldp+324,(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_fsm_stateNext_string),104);
    tracep->fullBit(oldp+328,(vlSelf->srio_clk));
    tracep->fullBit(oldp+329,(vlSelf->reset));
    tracep->fullBit(oldp+330,(vlSelf->iresp_stream_valid));
    tracep->fullBit(oldp+331,(vlSelf->iresp_stream_ready));
    tracep->fullQData(oldp+332,(vlSelf->iresp_stream_payload),64);
    tracep->fullQData(oldp+334,((((QData)((IData)(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_tid)) 
                                  << 0x38U) | (((QData)((IData)(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_ftype)) 
                                                << 0x34U) 
                                               | (((QData)((IData)(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_ttype)) 
                                                   << 0x30U) 
                                                  | (((QData)((IData)(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_prio)) 
                                                      << 0x2dU) 
                                                     | (((QData)((IData)(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_size)) 
                                                         << 0x24U) 
                                                        | vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_addr)))))),64);
    tracep->fullBit(oldp+336,((((2U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_ftype)) 
                                | (0xaU == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_ftype))) 
                               & (0U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__current_beat_cnt)))));
    tracep->fullBit(oldp+337,((((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__current_beat_cnt) 
                                == (0x1fU & ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_size) 
                                             >> 3U))) 
                               & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__ireq_tvalid))));
    tracep->fullBit(oldp+338,((((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__compare_received) 
                                & (0x200ULL == (0xf00ULL 
                                                & vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__read_queue_data))) 
                               & ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo_io_pop_valid) 
                                  & (~ (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_full))))));
    tracep->fullBit(oldp+339,(((0xffU == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_popPtr_value)) 
                               & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_popPtr_willIncrement))));
    tracep->fullBit(oldp+340,(((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_pushing) 
                               != (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_popping))));
    tracep->fullBit(oldp+341,((IData)(((0xa0000000000000ULL 
                                        == (0xf0000000000000ULL 
                                            & vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT___zz_logic_ram_port0)) 
                                       & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo_io_pop_valid)))));
    tracep->fullBit(oldp+342,((((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__first_beat) 
                                & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo_io_pop_valid)) 
                               & (0x120000ULL == (0xff0000ULL 
                                                  & vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT___zz_logic_ram_port0)))));
    tracep->fullBit(oldp+343,((((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__current_beat_cnt) 
                                == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__number_of_data_beats)) 
                               & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__tresp_tvalid))));
    tracep->fullCData(oldp+344,(2U),4);
    tracep->fullCData(oldp+345,(5U),4);
    tracep->fullCData(oldp+346,(6U),4);
    tracep->fullCData(oldp+347,(0xaU),4);
    tracep->fullCData(oldp+348,(0xbU),4);
    tracep->fullCData(oldp+349,(0xdU),4);
    tracep->fullCData(oldp+350,(9U),4);
    tracep->fullCData(oldp+351,(4U),4);
    tracep->fullCData(oldp+352,(0U),4);
    tracep->fullCData(oldp+353,(8U),4);
    tracep->fullCData(oldp+354,(0xffU),8);
    tracep->fullIData(oldp+355,(0xff00ffU),32);
    tracep->fullIData(oldp+356,(0xffU),32);
    tracep->fullBit(oldp+357,(1U));
    tracep->fullCData(oldp+358,(1U),4);
    tracep->fullCData(oldp+359,(3U),4);
    tracep->fullCData(oldp+360,(7U),4);
    tracep->fullBit(oldp+361,(0U));
    tracep->fullIData(oldp+362,(0x7d0U),32);
    tracep->fullQData(oldp+363,(0x2710ULL),64);
    tracep->fullQData(oldp+365,(0x4e20ULL),64);
    tracep->fullQData(oldp+367,(0x4e2aULL),64);
    tracep->fullQData(oldp+369,(0x7530ULL),64);
    tracep->fullQData(oldp+371,(0x9c40ULL),64);
    tracep->fullQData(oldp+373,(0xc350ULL),64);
    tracep->fullQData(oldp+375,(0xea60ULL),64);
    tracep->fullQData(oldp+377,(0x11170ULL),64);
    tracep->fullQData(oldp+379,(0x13880ULL),64);
    tracep->fullQData(oldp+381,(0ULL),64);
    tracep->fullQData(oldp+383,(0x202206011514ULL),64);
    tracep->fullSData(oldp+385,(0xffU),16);
    tracep->fullQData(oldp+386,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_dout),64);
}
