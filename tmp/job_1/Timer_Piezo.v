// Generator : SpinalHDL v1.8.0    git head : 4e3563a282582b41f4eaafc503787757251d23ea
// Component : Timer_Piezo
// Git hash  : f5ddcb1ebf9f3ce9c9d1466683ee01761d80916d

`timescale 1ns/1ps

module Timer_Piezo (
  input      [15:0]   dt_s,
  input               tick,
  output              trigger,
  input               clk,
  input               reset
);

  wire                timer_1_io_full;
  wire       [15:0]   timer_1_io_value;
  reg                 timer_reset;

  Timer timer_1 (
    .io_tick  (tick                  ), //i
    .io_clear (timer_reset           ), //i
    .io_limit (dt_s[15:0]            ), //i
    .io_full  (timer_1_io_full       ), //o
    .io_value (timer_1_io_value[15:0]), //o
    .clk      (clk                   ), //i
    .reset    (reset                 )  //i
  );
  assign trigger = timer_1_io_full; // @[Timer_Piezo.scala 20:14]
  always @(posedge clk or posedge reset) begin
    if(reset) begin
      timer_reset <= 1'b1; // @[Data.scala 400:33]
    end else begin
      timer_reset <= 1'b0; // @[Timer_Piezo.scala 16:15]
      if(timer_1_io_full) begin
        timer_reset <= 1'b1; // @[Timer_Piezo.scala 22:17]
      end
    end
  end


endmodule

module Timer (
  input               io_tick,
  input               io_clear,
  input      [15:0]   io_limit,
  output              io_full,
  output     [15:0]   io_value,
  input               clk,
  input               reset
);

  wire       [15:0]   _zz_counter;
  wire       [0:0]    _zz_counter_1;
  reg        [15:0]   counter;
  wire                limitHit;
  reg                 inhibitFull;

  assign _zz_counter_1 = (! limitHit);
  assign _zz_counter = {15'd0, _zz_counter_1};
  assign limitHit = (counter == io_limit); // @[BaseType.scala 305:24]
  assign io_full = ((limitHit && io_tick) && (! inhibitFull)); // @[Timer.scala 27:12]
  assign io_value = counter; // @[Timer.scala 28:12]
  always @(posedge clk or posedge reset) begin
    if(reset) begin
      inhibitFull <= 1'b0; // @[Data.scala 400:33]
    end else begin
      if(io_tick) begin
        inhibitFull <= limitHit; // @[Timer.scala 20:17]
      end
      if(io_clear) begin
        inhibitFull <= 1'b0; // @[Timer.scala 25:17]
      end
    end
  end

  always @(posedge clk) begin
    if(io_tick) begin
      counter <= (counter + _zz_counter); // @[Timer.scala 21:13]
    end
    if(io_clear) begin
      counter <= 16'h0; // @[Timer.scala 24:13]
    end
  end


endmodule
