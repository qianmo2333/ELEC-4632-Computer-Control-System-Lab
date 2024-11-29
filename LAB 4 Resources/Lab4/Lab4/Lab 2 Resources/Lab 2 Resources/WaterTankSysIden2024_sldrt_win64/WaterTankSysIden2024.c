/*
 * WaterTankSysIden2024.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "WaterTankSysIden2024".
 *
 * Model version              : 9.3
 * Simulink Coder version : 23.2 (R2023b) 01-Aug-2023
 * C source code generated on : Mon Nov  4 15:20:41 2024
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "WaterTankSysIden2024.h"
#include "rtwtypes.h"
#include <string.h>
#include "rt_nonfinite.h"
#include "WaterTankSysIden2024_dt.h"

/* options for Simulink Desktop Real-Time board 0 */
static double SLDRTBoardOptions0[] = {
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
};

/* list of Simulink Desktop Real-Time timers */
const int SLDRTTimerCount = 2;
const double SLDRTTimers[4] = {
  0.75, 0.0,
  172.5, 0.0,
};

/* list of Simulink Desktop Real-Time boards */
const int SLDRTBoardCount = 1;
SLDRTBOARD SLDRTBoards[1] = {
  { "National_Instruments/PCIe-6351", 4294967295U, 7, SLDRTBoardOptions0 },
};

/* Block signals (default storage) */
B_WaterTankSysIden2024_T WaterTankSysIden2024_B;

/* Block states (default storage) */
DW_WaterTankSysIden2024_T WaterTankSysIden2024_DW;

/* Real-time model */
static RT_MODEL_WaterTankSysIden2024_T WaterTankSysIden2024_M_;
RT_MODEL_WaterTankSysIden2024_T *const WaterTankSysIden2024_M =
  &WaterTankSysIden2024_M_;
static void rate_monotonic_scheduler(void);
time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
{
  rtmSampleHitPtr[1] = rtmStepTask(WaterTankSysIden2024_M, 1);
  rtmSampleHitPtr[2] = rtmStepTask(WaterTankSysIden2024_M, 2);
  UNUSED_PARAMETER(rtmNumSampTimes);
  UNUSED_PARAMETER(rtmTimingData);
  UNUSED_PARAMETER(rtmPerTaskSampleHits);
  return(-1);
}

/*
 *         This function updates active task flag for each subrate
 *         and rate transition flags for tasks that exchange data.
 *         The function assumes rate-monotonic multitasking scheduler.
 *         The function must be called at model base rate so that
 *         the generated code self-manages all its subrates and rate
 *         transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 1 shares data with slower tid rate: 2 */
  if (WaterTankSysIden2024_M->Timing.TaskCounters.TID[1] == 0) {
    WaterTankSysIden2024_M->Timing.RateInteraction.TID1_2 =
      (WaterTankSysIden2024_M->Timing.TaskCounters.TID[2] == 0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    WaterTankSysIden2024_M->Timing.perTaskSampleHits[5] =
      WaterTankSysIden2024_M->Timing.RateInteraction.TID1_2;
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (WaterTankSysIden2024_M->Timing.TaskCounters.TID[2])++;
  if ((WaterTankSysIden2024_M->Timing.TaskCounters.TID[2]) > 229) {/* Sample time: [172.5s, 0.0s] */
    WaterTankSysIden2024_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/* Model output function for TID0 */
void WaterTankSysIden2024_output0(void) /* Sample time: [0.0s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_OriginalOutput;
  real_T rtb_ActivationGainTANK2;
  real_T u0;
  int32_T cff;
  int32_T j;

  {                                    /* Sample time: [0.0s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* S-Function (sldrtai): '<S2>/Analog Input1' */
  /* S-Function Block: <S2>/Analog Input1 */
  {
    ANALOGIOPARM parm;
    parm.mode = (RANGEMODE) WaterTankSysIden2024_P.AnalogInput1_RangeMode;
    parm.rangeidx = WaterTankSysIden2024_P.AnalogInput1_VoltRange;
    RTBIO_DriverIO(0, ANALOGINPUT, IOREAD, 1,
                   &WaterTankSysIden2024_P.AnalogInput1_Channels,
                   &WaterTankSysIden2024_B.OriginalOutput, &parm);
  }

  /* S-Function (sldrtai): '<S2>/Analog Input2' */
  /* S-Function Block: <S2>/Analog Input2 */
  {
    ANALOGIOPARM parm;
    parm.mode = (RANGEMODE) WaterTankSysIden2024_P.AnalogInput2_RangeMode;
    parm.rangeidx = WaterTankSysIden2024_P.AnalogInput2_VoltRange;
    RTBIO_DriverIO(0, ANALOGINPUT, IOREAD, 1,
                   &WaterTankSysIden2024_P.AnalogInput2_Channels,
                   &rtb_OriginalOutput, &parm);
  }

  /* DiscreteFir: '<S2>/Discrete FIR Filter1' */
  rtb_ActivationGainTANK2 = WaterTankSysIden2024_B.OriginalOutput *
    WaterTankSysIden2024_P.DiscreteFIRFilter1_Coefficients[0];
  cff = 1;
  for (j = WaterTankSysIden2024_DW.DiscreteFIRFilter1_circBuf; j < 4; j++) {
    rtb_ActivationGainTANK2 +=
      WaterTankSysIden2024_DW.DiscreteFIRFilter1_states[j] *
      WaterTankSysIden2024_P.DiscreteFIRFilter1_Coefficients[cff];
    cff++;
  }

  for (j = 0; j < WaterTankSysIden2024_DW.DiscreteFIRFilter1_circBuf; j++) {
    rtb_ActivationGainTANK2 +=
      WaterTankSysIden2024_DW.DiscreteFIRFilter1_states[j] *
      WaterTankSysIden2024_P.DiscreteFIRFilter1_Coefficients[cff];
    cff++;
  }

  /* DiscreteFir: '<S2>/Discrete FIR Filter1' */
  WaterTankSysIden2024_B.NoiseReducedOutput = rtb_ActivationGainTANK2;

  /* RateTransition: '<Root>/Rate Transition' */
  if (WaterTankSysIden2024_M->Timing.RateInteraction.TID1_2) {
    /* RateTransition: '<Root>/Rate Transition' */
    WaterTankSysIden2024_B.OffsetFreeInput =
      WaterTankSysIden2024_DW.RateTransition_Buffer0;
  }

  /* End of RateTransition: '<Root>/Rate Transition' */

  /* Sum: '<Root>/Sum' incorporates:
   *  Constant: '<Root>/u_offset'
   */
  WaterTankSysIden2024_B.Sum = WaterTankSysIden2024_P.u_offset_Value +
    WaterTankSysIden2024_B.OffsetFreeInput;

  /* ManualSwitch: '<Root>/Manual Switch' incorporates:
   *  Gain: '<Root>/Gain'
   *  Step: '<Root>/Step'
   */
  if (WaterTankSysIden2024_P.ManualSwitch_CurrentSetting == 1) {
    rtb_ActivationGainTANK2 = WaterTankSysIden2024_B.Sum;
  } else {
    if (WaterTankSysIden2024_M->Timing.t[0] < WaterTankSysIden2024_P.Step_Time)
    {
      /* Step: '<Root>/Step' */
      rtb_ActivationGainTANK2 = WaterTankSysIden2024_P.Step_Y0;
    } else {
      /* Step: '<Root>/Step' */
      rtb_ActivationGainTANK2 = WaterTankSysIden2024_P.Step_YFinal;
    }

    rtb_ActivationGainTANK2 *= WaterTankSysIden2024_P.Gain_Gain;
  }

  /* End of ManualSwitch: '<Root>/Manual Switch' */

  /* Gain: '<Root>/Activation Gain TANK#1' */
  u0 = WaterTankSysIden2024_P.ActivationGainTANK1_Gain * rtb_ActivationGainTANK2;

  /* Saturate: '<Root>/Saturation TANK#1' */
  if (u0 > WaterTankSysIden2024_P.SaturationTANK1_UpperSat) {
    /* Saturate: '<Root>/Saturation TANK#1' */
    WaterTankSysIden2024_B.ActualInput =
      WaterTankSysIden2024_P.SaturationTANK1_UpperSat;
  } else if (u0 < WaterTankSysIden2024_P.SaturationTANK1_LowerSat) {
    /* Saturate: '<Root>/Saturation TANK#1' */
    WaterTankSysIden2024_B.ActualInput =
      WaterTankSysIden2024_P.SaturationTANK1_LowerSat;
  } else {
    /* Saturate: '<Root>/Saturation TANK#1' */
    WaterTankSysIden2024_B.ActualInput = u0;
  }

  /* End of Saturate: '<Root>/Saturation TANK#1' */
  /* Gain: '<Root>/Activation Gain TANK#2' */
  u0 = WaterTankSysIden2024_P.ActivationGainTANK2_Gain * rtb_ActivationGainTANK2;

  /* Saturate: '<Root>/Saturation TANK#2' */
  if (u0 > WaterTankSysIden2024_P.SaturationTANK2_UpperSat) {
    /* Saturate: '<Root>/Saturation TANK#2' */
    WaterTankSysIden2024_B.SaturationTANK2 =
      WaterTankSysIden2024_P.SaturationTANK2_UpperSat;
  } else if (u0 < WaterTankSysIden2024_P.SaturationTANK2_LowerSat) {
    /* Saturate: '<Root>/Saturation TANK#2' */
    WaterTankSysIden2024_B.SaturationTANK2 =
      WaterTankSysIden2024_P.SaturationTANK2_LowerSat;
  } else {
    /* Saturate: '<Root>/Saturation TANK#2' */
    WaterTankSysIden2024_B.SaturationTANK2 = u0;
  }

  /* End of Saturate: '<Root>/Saturation TANK#2' */

  /* S-Function (sldrtao): '<S2>/Analog Output1' */
  /* S-Function Block: <S2>/Analog Output1 */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) WaterTankSysIden2024_P.AnalogOutput1_RangeMode;
      parm.rangeidx = WaterTankSysIden2024_P.AnalogOutput1_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &WaterTankSysIden2024_P.AnalogOutput1_Channels, ((real_T*)
        (&WaterTankSysIden2024_B.ActualInput)), &parm);
    }
  }

  /* S-Function (sldrtao): '<S2>/Analog Output2' */
  /* S-Function Block: <S2>/Analog Output2 */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) WaterTankSysIden2024_P.AnalogOutput2_RangeMode;
      parm.rangeidx = WaterTankSysIden2024_P.AnalogOutput2_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &WaterTankSysIden2024_P.AnalogOutput2_Channels, ((real_T*)
        (&WaterTankSysIden2024_B.SaturationTANK2)), &parm);
    }
  }
}

/* Model update function for TID0 */
void WaterTankSysIden2024_update0(void) /* Sample time: [0.0s, 0.0s] */
{
  /* Update for DiscreteFir: '<S2>/Discrete FIR Filter1' */
  /* Update circular buffer index */
  WaterTankSysIden2024_DW.DiscreteFIRFilter1_circBuf--;
  if (WaterTankSysIden2024_DW.DiscreteFIRFilter1_circBuf < 0) {
    WaterTankSysIden2024_DW.DiscreteFIRFilter1_circBuf = 3;
  }

  /* Update circular buffer */
  WaterTankSysIden2024_DW.DiscreteFIRFilter1_states[WaterTankSysIden2024_DW.DiscreteFIRFilter1_circBuf]
    = WaterTankSysIden2024_B.OriginalOutput;

  /* End of Update for DiscreteFir: '<S2>/Discrete FIR Filter1' */

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++WaterTankSysIden2024_M->Timing.clockTick0)) {
    ++WaterTankSysIden2024_M->Timing.clockTickH0;
  }

  WaterTankSysIden2024_M->Timing.t[0] =
    WaterTankSysIden2024_M->Timing.clockTick0 *
    WaterTankSysIden2024_M->Timing.stepSize0 +
    WaterTankSysIden2024_M->Timing.clockTickH0 *
    WaterTankSysIden2024_M->Timing.stepSize0 * 4294967296.0;

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick1"
   * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++WaterTankSysIden2024_M->Timing.clockTick1)) {
    ++WaterTankSysIden2024_M->Timing.clockTickH1;
  }

  WaterTankSysIden2024_M->Timing.t[1] =
    WaterTankSysIden2024_M->Timing.clockTick1 *
    WaterTankSysIden2024_M->Timing.stepSize1 +
    WaterTankSysIden2024_M->Timing.clockTickH1 *
    WaterTankSysIden2024_M->Timing.stepSize1 * 4294967296.0;
}

/* Model output function for TID2 */
void WaterTankSysIden2024_output2(void) /* Sample time: [172.5s, 0.0s] */
{
  real_T rtb_Output;
  uint8_T rtb_FixPtSum1;

  /* MultiPortSwitch: '<S1>/Output' incorporates:
   *  Constant: '<S1>/Vector'
   *  UnitDelay: '<S3>/Output'
   */
  rtb_Output =
    WaterTankSysIden2024_P.RepeatingSequenceStair_OutValues[WaterTankSysIden2024_DW.Output_DSTATE];

  /* RateTransition: '<Root>/Rate Transition' */
  WaterTankSysIden2024_DW.RateTransition_Buffer0 = rtb_Output;

  /* Sum: '<S4>/FixPt Sum1' incorporates:
   *  Constant: '<S4>/FixPt Constant'
   *  UnitDelay: '<S3>/Output'
   */
  rtb_FixPtSum1 = (uint8_T)(WaterTankSysIden2024_DW.Output_DSTATE +
    WaterTankSysIden2024_P.FixPtConstant_Value);

  /* Switch: '<S5>/FixPt Switch' */
  if (rtb_FixPtSum1 > WaterTankSysIden2024_P.LimitedCounter_uplimit) {
    /* Switch: '<S5>/FixPt Switch' incorporates:
     *  Constant: '<S5>/Constant'
     */
    WaterTankSysIden2024_B.FixPtSwitch = WaterTankSysIden2024_P.Constant_Value;
  } else {
    /* Switch: '<S5>/FixPt Switch' */
    WaterTankSysIden2024_B.FixPtSwitch = rtb_FixPtSum1;
  }

  /* End of Switch: '<S5>/FixPt Switch' */
}

/* Model update function for TID2 */
void WaterTankSysIden2024_update2(void) /* Sample time: [172.5s, 0.0s] */
{
  /* Update for UnitDelay: '<S3>/Output' */
  WaterTankSysIden2024_DW.Output_DSTATE = WaterTankSysIden2024_B.FixPtSwitch;

  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick2"
   * and "Timing.stepSize2". Size of "clockTick2" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick2 and the high bits
   * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++WaterTankSysIden2024_M->Timing.clockTick2)) {
    ++WaterTankSysIden2024_M->Timing.clockTickH2;
  }

  WaterTankSysIden2024_M->Timing.t[2] =
    WaterTankSysIden2024_M->Timing.clockTick2 *
    WaterTankSysIden2024_M->Timing.stepSize2 +
    WaterTankSysIden2024_M->Timing.clockTickH2 *
    WaterTankSysIden2024_M->Timing.stepSize2 * 4294967296.0;
}

/* Use this function only if you need to maintain compatibility with an existing static main program. */
void WaterTankSysIden2024_output(int_T tid)
{
  switch (tid) {
   case 0 :
    WaterTankSysIden2024_output0();
    break;

   case 2 :
    WaterTankSysIden2024_output2();
    break;

   default :
    /* do nothing */
    break;
  }
}

/* Use this function only if you need to maintain compatibility with an existing static main program. */
void WaterTankSysIden2024_update(int_T tid)
{
  switch (tid) {
   case 0 :
    WaterTankSysIden2024_update0();
    break;

   case 2 :
    WaterTankSysIden2024_update2();
    break;

   default :
    /* do nothing */
    break;
  }
}

/* Model initialize function */
void WaterTankSysIden2024_initialize(void)
{
  /* Start for RateTransition: '<Root>/Rate Transition' */
  WaterTankSysIden2024_B.OffsetFreeInput =
    WaterTankSysIden2024_P.RateTransition_InitialCondition;

  /* Start for S-Function (sldrtao): '<S2>/Analog Output1' */

  /* S-Function Block: <S2>/Analog Output1 */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) WaterTankSysIden2024_P.AnalogOutput1_RangeMode;
      parm.rangeidx = WaterTankSysIden2024_P.AnalogOutput1_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &WaterTankSysIden2024_P.AnalogOutput1_Channels,
                     &WaterTankSysIden2024_P.AnalogOutput1_InitialValue, &parm);
    }
  }

  /* Start for S-Function (sldrtao): '<S2>/Analog Output2' */

  /* S-Function Block: <S2>/Analog Output2 */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) WaterTankSysIden2024_P.AnalogOutput2_RangeMode;
      parm.rangeidx = WaterTankSysIden2024_P.AnalogOutput2_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &WaterTankSysIden2024_P.AnalogOutput2_Channels,
                     &WaterTankSysIden2024_P.AnalogOutput2_InitialValue, &parm);
    }
  }

  /* InitializeConditions for DiscreteFir: '<S2>/Discrete FIR Filter1' */
  WaterTankSysIden2024_DW.DiscreteFIRFilter1_circBuf = 0;
  WaterTankSysIden2024_DW.DiscreteFIRFilter1_states[0] =
    WaterTankSysIden2024_P.DiscreteFIRFilter1_InitialStates;
  WaterTankSysIden2024_DW.DiscreteFIRFilter1_states[1] =
    WaterTankSysIden2024_P.DiscreteFIRFilter1_InitialStates;
  WaterTankSysIden2024_DW.DiscreteFIRFilter1_states[2] =
    WaterTankSysIden2024_P.DiscreteFIRFilter1_InitialStates;
  WaterTankSysIden2024_DW.DiscreteFIRFilter1_states[3] =
    WaterTankSysIden2024_P.DiscreteFIRFilter1_InitialStates;

  /* InitializeConditions for RateTransition: '<Root>/Rate Transition' */
  WaterTankSysIden2024_DW.RateTransition_Buffer0 =
    WaterTankSysIden2024_P.RateTransition_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S3>/Output' */
  WaterTankSysIden2024_DW.Output_DSTATE =
    WaterTankSysIden2024_P.Output_InitialCondition;
}

/* Model terminate function */
void WaterTankSysIden2024_terminate(void)
{
  /* Terminate for S-Function (sldrtao): '<S2>/Analog Output1' */

  /* S-Function Block: <S2>/Analog Output1 */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) WaterTankSysIden2024_P.AnalogOutput1_RangeMode;
      parm.rangeidx = WaterTankSysIden2024_P.AnalogOutput1_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &WaterTankSysIden2024_P.AnalogOutput1_Channels,
                     &WaterTankSysIden2024_P.AnalogOutput1_FinalValue, &parm);
    }
  }

  /* Terminate for S-Function (sldrtao): '<S2>/Analog Output2' */

  /* S-Function Block: <S2>/Analog Output2 */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) WaterTankSysIden2024_P.AnalogOutput2_RangeMode;
      parm.rangeidx = WaterTankSysIden2024_P.AnalogOutput2_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &WaterTankSysIden2024_P.AnalogOutput2_Channels,
                     &WaterTankSysIden2024_P.AnalogOutput2_FinalValue, &parm);
    }
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  if (tid == 1)
    tid = 0;
  WaterTankSysIden2024_output(tid);
}

void MdlUpdate(int_T tid)
{
  if (tid == 1)
    tid = 0;
  WaterTankSysIden2024_update(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  WaterTankSysIden2024_initialize();
}

void MdlTerminate(void)
{
  WaterTankSysIden2024_terminate();
}

/* Registration function */
RT_MODEL_WaterTankSysIden2024_T *WaterTankSysIden2024(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)WaterTankSysIden2024_M, 0,
                sizeof(RT_MODEL_WaterTankSysIden2024_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&WaterTankSysIden2024_M->solverInfo,
                          &WaterTankSysIden2024_M->Timing.simTimeStep);
    rtsiSetTPtr(&WaterTankSysIden2024_M->solverInfo, &rtmGetTPtr
                (WaterTankSysIden2024_M));
    rtsiSetStepSizePtr(&WaterTankSysIden2024_M->solverInfo,
                       &WaterTankSysIden2024_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&WaterTankSysIden2024_M->solverInfo,
                          (&rtmGetErrorStatus(WaterTankSysIden2024_M)));
    rtsiSetRTModelPtr(&WaterTankSysIden2024_M->solverInfo,
                      WaterTankSysIden2024_M);
  }

  rtsiSetSimTimeStep(&WaterTankSysIden2024_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&WaterTankSysIden2024_M->solverInfo,"FixedStepDiscrete");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = WaterTankSysIden2024_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "WaterTankSysIden2024_M points to
       static memory which is guaranteed to be non-NULL" */
    WaterTankSysIden2024_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    WaterTankSysIden2024_M->Timing.sampleTimes =
      (&WaterTankSysIden2024_M->Timing.sampleTimesArray[0]);
    WaterTankSysIden2024_M->Timing.offsetTimes =
      (&WaterTankSysIden2024_M->Timing.offsetTimesArray[0]);

    /* task periods */
    WaterTankSysIden2024_M->Timing.sampleTimes[0] = (0.0);
    WaterTankSysIden2024_M->Timing.sampleTimes[1] = (0.75);
    WaterTankSysIden2024_M->Timing.sampleTimes[2] = (172.5);

    /* task offsets */
    WaterTankSysIden2024_M->Timing.offsetTimes[0] = (0.0);
    WaterTankSysIden2024_M->Timing.offsetTimes[1] = (0.0);
    WaterTankSysIden2024_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(WaterTankSysIden2024_M, &WaterTankSysIden2024_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = WaterTankSysIden2024_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits =
      WaterTankSysIden2024_M->Timing.perTaskSampleHitsArray;
    WaterTankSysIden2024_M->Timing.perTaskSampleHits = (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    WaterTankSysIden2024_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(WaterTankSysIden2024_M, 1999.5);
  WaterTankSysIden2024_M->Timing.stepSize0 = 0.75;
  WaterTankSysIden2024_M->Timing.stepSize1 = 0.75;
  WaterTankSysIden2024_M->Timing.stepSize2 = 172.5;

  /* External mode info */
  WaterTankSysIden2024_M->Sizes.checksums[0] = (3538193518U);
  WaterTankSysIden2024_M->Sizes.checksums[1] = (1569650867U);
  WaterTankSysIden2024_M->Sizes.checksums[2] = (1391335520U);
  WaterTankSysIden2024_M->Sizes.checksums[3] = (3517014851U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    WaterTankSysIden2024_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(WaterTankSysIden2024_M->extModeInfo,
      &WaterTankSysIden2024_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(WaterTankSysIden2024_M->extModeInfo,
                        WaterTankSysIden2024_M->Sizes.checksums);
    rteiSetTPtr(WaterTankSysIden2024_M->extModeInfo, rtmGetTPtr
                (WaterTankSysIden2024_M));
  }

  WaterTankSysIden2024_M->solverInfoPtr = (&WaterTankSysIden2024_M->solverInfo);
  WaterTankSysIden2024_M->Timing.stepSize = (0.75);
  rtsiSetFixedStepSize(&WaterTankSysIden2024_M->solverInfo, 0.75);
  rtsiSetSolverMode(&WaterTankSysIden2024_M->solverInfo,
                    SOLVER_MODE_MULTITASKING);

  /* block I/O */
  WaterTankSysIden2024_M->blockIO = ((void *) &WaterTankSysIden2024_B);
  (void) memset(((void *) &WaterTankSysIden2024_B), 0,
                sizeof(B_WaterTankSysIden2024_T));

  /* parameters */
  WaterTankSysIden2024_M->defaultParam = ((real_T *)&WaterTankSysIden2024_P);

  /* states (dwork) */
  WaterTankSysIden2024_M->dwork = ((void *) &WaterTankSysIden2024_DW);
  (void) memset((void *)&WaterTankSysIden2024_DW, 0,
                sizeof(DW_WaterTankSysIden2024_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    WaterTankSysIden2024_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 23;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  WaterTankSysIden2024_M->Sizes.numContStates = (0);/* Number of continuous states */
  WaterTankSysIden2024_M->Sizes.numY = (0);/* Number of model outputs */
  WaterTankSysIden2024_M->Sizes.numU = (0);/* Number of model inputs */
  WaterTankSysIden2024_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  WaterTankSysIden2024_M->Sizes.numSampTimes = (3);/* Number of sample times */
  WaterTankSysIden2024_M->Sizes.numBlocks = (25);/* Number of blocks */
  WaterTankSysIden2024_M->Sizes.numBlockIO = (7);/* Number of block outputs */
  WaterTankSysIden2024_M->Sizes.numBlockPrms = (50);/* Sum of parameter "widths" */
  return WaterTankSysIden2024_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
