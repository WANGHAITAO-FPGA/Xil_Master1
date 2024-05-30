// Generator : SpinalHDL v1.8.0    git head : 4e3563a282582b41f4eaafc503787757251d23ea
// Component : DataConv
// Git hash  : f5ddcb1ebf9f3ce9c9d1466683ee01761d80916d

`timescale 1ns/1ps

module DataConv (
  input               datain_valid,
  input      [31:0]   datain_payload,
  input               intr,
  output              dataout_valid,
  input               dataout_ready,
  output              dataout_payload_last,
  output     [31:0]   dataout_payload_fragment,
  input               clk,
  input               reset
);

  wire                streamfifo_1_io_pop_ready;
  wire                streamfifo_1_io_push_ready;
  wire                streamfifo_1_io_pop_valid;
  wire       [31:0]   streamfifo_1_io_pop_payload;
  wire       [12:0]   streamfifo_1_io_occupancy;
  wire       [12:0]   streamfifo_1_io_availability;
  reg                 intr_1;
  reg                 ready;
  reg                 intr_1_regNext;
  wire                when_Piezo_Process_l18;
  wire                when_Piezo_Process_l21;
  wire                dataout_fire;

  StreamFifo streamfifo_1 (
    .io_push_valid   (datain_valid                      ), //i
    .io_push_ready   (streamfifo_1_io_push_ready        ), //o
    .io_push_payload (datain_payload[31:0]              ), //i
    .io_pop_valid    (streamfifo_1_io_pop_valid         ), //o
    .io_pop_ready    (streamfifo_1_io_pop_ready         ), //i
    .io_pop_payload  (streamfifo_1_io_pop_payload[31:0] ), //o
    .io_flush        (1'b0                              ), //i
    .io_occupancy    (streamfifo_1_io_occupancy[12:0]   ), //o
    .io_availability (streamfifo_1_io_availability[12:0]), //o
    .clk             (clk                               ), //i
    .reset           (reset                             )  //i
  );
  assign when_Piezo_Process_l18 = (intr_1 && (! intr_1_regNext)); // @[BaseType.scala 305:24]
  assign when_Piezo_Process_l21 = (streamfifo_1_io_occupancy == 13'h0); // @[BaseType.scala 305:24]
  assign dataout_payload_fragment = streamfifo_1_io_pop_payload; // @[Piezo_Process.scala 26:31]
  assign dataout_valid = (streamfifo_1_io_pop_valid && ready); // @[Piezo_Process.scala 27:20]
  assign streamfifo_1_io_pop_ready = (dataout_ready && ready); // @[Piezo_Process.scala 28:27]
  assign dataout_fire = (dataout_valid && dataout_ready); // @[BaseType.scala 305:24]
  assign dataout_payload_last = ((streamfifo_1_io_occupancy == 13'h0001) && dataout_fire); // @[Piezo_Process.scala 29:27]
  always @(posedge clk or posedge reset) begin
    if(reset) begin
      intr_1 <= 1'b0; // @[Data.scala 400:33]
      ready <= 1'b0; // @[Data.scala 400:33]
    end else begin
      intr_1 <= intr; // @[Piezo_Process.scala 16:8]
      if(when_Piezo_Process_l18) begin
        ready <= 1'b1; // @[Piezo_Process.scala 19:11]
      end
      if(when_Piezo_Process_l21) begin
        ready <= 1'b0; // @[Piezo_Process.scala 22:11]
      end
    end
  end

  always @(posedge clk) begin
    intr_1_regNext <= intr_1; // @[Reg.scala 39:30]
  end


endmodule

module StreamFifo (
  input               io_push_valid,
  output              io_push_ready,
  input      [31:0]   io_push_payload,
  output              io_pop_valid,
  input               io_pop_ready,
  output     [31:0]   io_pop_payload,
  input               io_flush,
  output     [12:0]   io_occupancy,
  output     [12:0]   io_availability,
  input               clk,
  input               reset
);

  reg        [31:0]   _zz_logic_ram_port0;
  wire       [11:0]   _zz_logic_pushPtr_valueNext;
  wire       [0:0]    _zz_logic_pushPtr_valueNext_1;
  wire       [11:0]   _zz_logic_popPtr_valueNext;
  wire       [0:0]    _zz_logic_popPtr_valueNext_1;
  wire                _zz_logic_ram_port;
  wire                _zz_io_pop_payload;
  wire       [11:0]   _zz_io_availability;
  reg                 _zz_1;
  reg                 logic_pushPtr_willIncrement;
  reg                 logic_pushPtr_willClear;
  reg        [11:0]   logic_pushPtr_valueNext;
  reg        [11:0]   logic_pushPtr_value;
  wire                logic_pushPtr_willOverflowIfInc;
  wire                logic_pushPtr_willOverflow;
  reg                 logic_popPtr_willIncrement;
  reg                 logic_popPtr_willClear;
  reg        [11:0]   logic_popPtr_valueNext;
  reg        [11:0]   logic_popPtr_value;
  wire                logic_popPtr_willOverflowIfInc;
  wire                logic_popPtr_willOverflow;
  wire                logic_ptrMatch;
  reg                 logic_risingOccupancy;
  wire                logic_pushing;
  wire                logic_popping;
  wire                logic_empty;
  wire                logic_full;
  reg                 _zz_io_pop_valid;
  wire                when_Stream_l1101;
  wire       [11:0]   logic_ptrDif;
  (* ram_style = "block" *) reg [31:0] logic_ram [0:4095];

  assign _zz_logic_pushPtr_valueNext_1 = logic_pushPtr_willIncrement;
  assign _zz_logic_pushPtr_valueNext = {11'd0, _zz_logic_pushPtr_valueNext_1};
  assign _zz_logic_popPtr_valueNext_1 = logic_popPtr_willIncrement;
  assign _zz_logic_popPtr_valueNext = {11'd0, _zz_logic_popPtr_valueNext_1};
  assign _zz_io_availability = (logic_popPtr_value - logic_pushPtr_value);
  assign _zz_io_pop_payload = 1'b1;
  always @(posedge clk) begin
    if(_zz_io_pop_payload) begin
      _zz_logic_ram_port0 <= logic_ram[logic_popPtr_valueNext];
    end
  end

  always @(posedge clk) begin
    if(_zz_1) begin
      logic_ram[logic_pushPtr_value] <= io_push_payload;
    end
  end

  always @(*) begin
    _zz_1 = 1'b0; // @[when.scala 47:16]
    if(logic_pushing) begin
      _zz_1 = 1'b1; // @[when.scala 52:10]
    end
  end

  always @(*) begin
    logic_pushPtr_willIncrement = 1'b0; // @[Utils.scala 536:23]
    if(logic_pushing) begin
      logic_pushPtr_willIncrement = 1'b1; // @[Utils.scala 540:41]
    end
  end

  always @(*) begin
    logic_pushPtr_willClear = 1'b0; // @[Utils.scala 537:19]
    if(io_flush) begin
      logic_pushPtr_willClear = 1'b1; // @[Utils.scala 539:33]
    end
  end

  assign logic_pushPtr_willOverflowIfInc = (logic_pushPtr_value == 12'hfff); // @[BaseType.scala 305:24]
  assign logic_pushPtr_willOverflow = (logic_pushPtr_willOverflowIfInc && logic_pushPtr_willIncrement); // @[BaseType.scala 305:24]
  always @(*) begin
    logic_pushPtr_valueNext = (logic_pushPtr_value + _zz_logic_pushPtr_valueNext); // @[Utils.scala 548:15]
    if(logic_pushPtr_willClear) begin
      logic_pushPtr_valueNext = 12'h0; // @[Utils.scala 558:15]
    end
  end

  always @(*) begin
    logic_popPtr_willIncrement = 1'b0; // @[Utils.scala 536:23]
    if(logic_popping) begin
      logic_popPtr_willIncrement = 1'b1; // @[Utils.scala 540:41]
    end
  end

  always @(*) begin
    logic_popPtr_willClear = 1'b0; // @[Utils.scala 537:19]
    if(io_flush) begin
      logic_popPtr_willClear = 1'b1; // @[Utils.scala 539:33]
    end
  end

  assign logic_popPtr_willOverflowIfInc = (logic_popPtr_value == 12'hfff); // @[BaseType.scala 305:24]
  assign logic_popPtr_willOverflow = (logic_popPtr_willOverflowIfInc && logic_popPtr_willIncrement); // @[BaseType.scala 305:24]
  always @(*) begin
    logic_popPtr_valueNext = (logic_popPtr_value + _zz_logic_popPtr_valueNext); // @[Utils.scala 548:15]
    if(logic_popPtr_willClear) begin
      logic_popPtr_valueNext = 12'h0; // @[Utils.scala 558:15]
    end
  end

  assign logic_ptrMatch = (logic_pushPtr_value == logic_popPtr_value); // @[BaseType.scala 305:24]
  assign logic_pushing = (io_push_valid && io_push_ready); // @[BaseType.scala 305:24]
  assign logic_popping = (io_pop_valid && io_pop_ready); // @[BaseType.scala 305:24]
  assign logic_empty = (logic_ptrMatch && (! logic_risingOccupancy)); // @[BaseType.scala 305:24]
  assign logic_full = (logic_ptrMatch && logic_risingOccupancy); // @[BaseType.scala 305:24]
  assign io_push_ready = (! logic_full); // @[Stream.scala 1097:19]
  assign io_pop_valid = ((! logic_empty) && (! (_zz_io_pop_valid && (! logic_full)))); // @[Stream.scala 1098:18]
  assign io_pop_payload = _zz_logic_ram_port0; // @[Stream.scala 1099:20]
  assign when_Stream_l1101 = (logic_pushing != logic_popping); // @[BaseType.scala 305:24]
  assign logic_ptrDif = (logic_pushPtr_value - logic_popPtr_value); // @[BaseType.scala 299:24]
  assign io_occupancy = {(logic_risingOccupancy && logic_ptrMatch),logic_ptrDif}; // @[Stream.scala 1114:20]
  assign io_availability = {((! logic_risingOccupancy) && logic_ptrMatch),_zz_io_availability}; // @[Stream.scala 1115:23]
  always @(posedge clk or posedge reset) begin
    if(reset) begin
      logic_pushPtr_value <= 12'h0; // @[Data.scala 400:33]
      logic_popPtr_value <= 12'h0; // @[Data.scala 400:33]
      logic_risingOccupancy <= 1'b0; // @[Data.scala 400:33]
      _zz_io_pop_valid <= 1'b0; // @[Data.scala 400:33]
    end else begin
      logic_pushPtr_value <= logic_pushPtr_valueNext; // @[Reg.scala 39:30]
      logic_popPtr_value <= logic_popPtr_valueNext; // @[Reg.scala 39:30]
      _zz_io_pop_valid <= (logic_popPtr_valueNext == logic_pushPtr_value); // @[Reg.scala 39:30]
      if(when_Stream_l1101) begin
        logic_risingOccupancy <= logic_pushing; // @[Stream.scala 1102:23]
      end
      if(io_flush) begin
        logic_risingOccupancy <= 1'b0; // @[Stream.scala 1129:23]
      end
    end
  end


endmodule
