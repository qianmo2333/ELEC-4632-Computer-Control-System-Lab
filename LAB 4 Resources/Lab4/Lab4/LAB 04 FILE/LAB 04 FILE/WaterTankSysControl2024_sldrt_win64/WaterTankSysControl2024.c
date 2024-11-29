/*
 * WaterTankSysControl2024.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "WaterTankSysControl2024".
 *
 * Model version              : 9.8
 * Simulink Coder version : 23.2 (R2023b) 01-Aug-2023
 * C source code generated on : Mon Nov  4 17:48:07 2024
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "WaterTankSysControl2024.h"
#include "rtwtypes.h"
#include <string.h>
#include "rt_nonfinite.h"
#include "WaterTankSysControl2024_dt.h"

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
  105.0, 0.0,
};

/* list of Simulink Desktop Real-Time boards */
const int SLDRTBoardCount = 1;
SLDRTBOARD SLDRTBoards[1] = {
  { "National_Instruments/PCIe-6351", 4294967295U, 7, SLDRTBoardOptions0 },
};

/* Block signals (default storage) */
B_WaterTankSysControl2024_T WaterTankSysControl2024_B;

/* Block states (default storage) */
DW_WaterTankSysControl2024_T WaterTankSysControl2024_DW;

/* Real-time model */
static RT_MODEL_WaterTankSysControl2024_T WaterTankSysControl2024_M_;
RT_MODEL_WaterTankSysControl2024_T *const WaterTankSysControl2024_M =
  &WaterTankSysControl2024_M_;
static void rate_monotonic_scheduler(void);
time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
{
  rtmSampleHitPtr[1] = rtmStepTask(WaterTankSysControl2024_M, 1);
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

  /* tid 0 shares data with slower tid rate: 1 */
  WaterTankSysControl2024_M->Timing.RateInteraction.TID0_1 =
    (WaterTankSysControl2024_M->Timing.TaskCounters.TID[1] == 0);

  /* update PerTaskSampleHits matrix for non-inline sfcn */
  WaterTankSysControl2024_M->Timing.perTaskSampleHits[1] =
    WaterTankSysControl2024_M->Timing.RateInteraction.TID0_1;

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (WaterTankSysControl2024_M->Timing.TaskCounters.TID[1])++;
  if ((WaterTankSysControl2024_M->Timing.TaskCounters.TID[1]) > 139) {/* Sample time: [105.0s, 0.0s] */
    WaterTankSysControl2024_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Model output function for TID0 */
void WaterTankSysControl2024_output0(void) /* Sample time: [0.75s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_OriginalOutput;
  real_T rtb_SaturationTANK4;
  real_T rtb_Sum2;
  real_T rtb_uk;
  int32_T cff;
  int32_T j;

  {                                    /* Sample time: [0.75s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* RateTransition: '<Root>/Rate Transition1' */
  if (WaterTankSysControl2024_M->Timing.RateInteraction.TID0_1) {
    /* RateTransition: '<Root>/Rate Transition1' */
    WaterTankSysControl2024_B.OffsetFreeReferenceSignaly_refk =
      WaterTankSysControl2024_DW.RateTransition1_Buffer0;
  }

  /* End of RateTransition: '<Root>/Rate Transition1' */

  /* Sum: '<Root>/Sum4' incorporates:
   *  Constant: '<Root>/Constant3'
   */
  WaterTankSysControl2024_B.ReferenceSignal = WaterTankSysControl2024_P.y_offset
    + WaterTankSysControl2024_B.OffsetFreeReferenceSignaly_refk;

  /* S-Function (sldrtai): '<S3>/Analog Input1' */
  /* S-Function Block: <S3>/Analog Input1 */
  {
    ANALOGIOPARM parm;
    parm.mode = (RANGEMODE) WaterTankSysControl2024_P.AnalogInput1_RangeMode;
    parm.rangeidx = WaterTankSysControl2024_P.AnalogInput1_VoltRange;
    RTBIO_DriverIO(0, ANALOGINPUT, IOREAD, 1,
                   &WaterTankSysControl2024_P.AnalogInput1_Channels,
                   &WaterTankSysControl2024_B.OriginalOutput, &parm);
  }

  /* S-Function (sldrtai): '<S3>/Analog Input2' */
  /* S-Function Block: <S3>/Analog Input2 */
  {
    ANALOGIOPARM parm;
    parm.mode = (RANGEMODE) WaterTankSysControl2024_P.AnalogInput2_RangeMode;
    parm.rangeidx = WaterTankSysControl2024_P.AnalogInput2_VoltRange;
    RTBIO_DriverIO(0, ANALOGINPUT, IOREAD, 1,
                   &WaterTankSysControl2024_P.AnalogInput2_Channels,
                   &rtb_OriginalOutput, &parm);
  }

  /* DiscreteFir: '<S3>/Discrete FIR Filter1' */
  rtb_uk = WaterTankSysControl2024_B.OriginalOutput *
    WaterTankSysControl2024_P.DiscreteFIRFilter1_Coefficients[0];
  cff = 1;
  for (j = WaterTankSysControl2024_DW.DiscreteFIRFilter1_circBuf; j < 4; j++) {
    rtb_uk += WaterTankSysControl2024_DW.DiscreteFIRFilter1_states[j] *
      WaterTankSysControl2024_P.DiscreteFIRFilter1_Coefficients[cff];
    cff++;
  }

  for (j = 0; j < WaterTankSysControl2024_DW.DiscreteFIRFilter1_circBuf; j++) {
    rtb_uk += WaterTankSysControl2024_DW.DiscreteFIRFilter1_states[j] *
      WaterTankSysControl2024_P.DiscreteFIRFilter1_Coefficients[cff];
    cff++;
  }

  /* DiscreteFir: '<S3>/Discrete FIR Filter1' */
  WaterTankSysControl2024_B.NoiseReducedOutput = rtb_uk;

  /* Sum: '<Root>/Sum3' incorporates:
   *  Delay: '<S1>/Delay'
   *  Gain: '<Root>/DC Gain  Compensation'
   *  Gain: '<S1>/Gain4'
   */
  rtb_uk = (-WaterTankSysControl2024_P.L[0] *
            WaterTankSysControl2024_DW.Delay_DSTATE[0] +
            -WaterTankSysControl2024_P.L[1] *
            WaterTankSysControl2024_DW.Delay_DSTATE[1]) +
    WaterTankSysControl2024_P.Gcl_1 *
    WaterTankSysControl2024_B.OffsetFreeReferenceSignaly_refk;

  /* Sum: '<Root>/Sum1' incorporates:
   *  Constant: '<Root>/Constant2'
   */
  rtb_SaturationTANK4 = WaterTankSysControl2024_P.u_offset + rtb_uk;

  /* Gain: '<Root>/Activation Gain TANK#3' */
  rtb_Sum2 = WaterTankSysControl2024_P.ActivationGainTANK3_Gain *
    rtb_SaturationTANK4;

  /* Saturate: '<Root>/Saturation TANK#3' */
  if (rtb_Sum2 > WaterTankSysControl2024_P.SaturationTANK3_UpperSat) {
    /* Saturate: '<Root>/Saturation TANK#3' */
    WaterTankSysControl2024_B.ActualInput =
      WaterTankSysControl2024_P.SaturationTANK3_UpperSat;
  } else if (rtb_Sum2 < WaterTankSysControl2024_P.SaturationTANK3_LowerSat) {
    /* Saturate: '<Root>/Saturation TANK#3' */
    WaterTankSysControl2024_B.ActualInput =
      WaterTankSysControl2024_P.SaturationTANK3_LowerSat;
  } else {
    /* Saturate: '<Root>/Saturation TANK#3' */
    WaterTankSysControl2024_B.ActualInput = rtb_Sum2;
  }

  /* End of Saturate: '<Root>/Saturation TANK#3' */
  /* Sum: '<S1>/Sum2' incorporates:
   *  Constant: '<Root>/Constant'
   *  Delay: '<S1>/Delay'
   *  Gain: '<S1>/Gain1'
   *  Sum: '<Root>/Sum5'
   */
  rtb_Sum2 = (WaterTankSysControl2024_B.NoiseReducedOutput -
              WaterTankSysControl2024_P.y_offset) -
    (WaterTankSysControl2024_P.C_obs[0] *
     WaterTankSysControl2024_DW.Delay_DSTATE[0] +
     WaterTankSysControl2024_P.C_obs[1] *
     WaterTankSysControl2024_DW.Delay_DSTATE[1]);

  /* Sum: '<S1>/Sum1' incorporates:
   *  Delay: '<S1>/Delay'
   *  Gain: '<S1>/Gain'
   *  Gain: '<S1>/Gain2'
   *  Gain: '<S1>/Gain3'
   */
  WaterTankSysControl2024_B.Sum1[0] = (WaterTankSysControl2024_P.K[0] * rtb_Sum2
    + WaterTankSysControl2024_P.H_obs[0] * rtb_uk) +
    (WaterTankSysControl2024_P.G_obs[0] *
     WaterTankSysControl2024_DW.Delay_DSTATE[0] +
     WaterTankSysControl2024_DW.Delay_DSTATE[1] *
     WaterTankSysControl2024_P.G_obs[2]);
  WaterTankSysControl2024_B.Sum1[1] = (WaterTankSysControl2024_P.K[1] * rtb_Sum2
    + WaterTankSysControl2024_P.H_obs[1] * rtb_uk) +
    (WaterTankSysControl2024_DW.Delay_DSTATE[0] *
     WaterTankSysControl2024_P.G_obs[1] +
     WaterTankSysControl2024_DW.Delay_DSTATE[1] *
     WaterTankSysControl2024_P.G_obs[3]);

  /* Gain: '<Root>/Activation Gain TANK#4' */
  rtb_SaturationTANK4 *= WaterTankSysControl2024_P.ActivationGainTANK4_Gain;

  /* Saturate: '<Root>/Saturation TANK#4' */
  if (rtb_SaturationTANK4 > WaterTankSysControl2024_P.SaturationTANK4_UpperSat)
  {
    rtb_SaturationTANK4 = WaterTankSysControl2024_P.SaturationTANK4_UpperSat;
  } else if (rtb_SaturationTANK4 <
             WaterTankSysControl2024_P.SaturationTANK4_LowerSat) {
    rtb_SaturationTANK4 = WaterTankSysControl2024_P.SaturationTANK4_LowerSat;
  }

  /* End of Saturate: '<Root>/Saturation TANK#4' */

  /* S-Function (sldrtao): '<S3>/Analog Output1' */
  /* S-Function Block: <S3>/Analog Output1 */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) WaterTankSysControl2024_P.AnalogOutput1_RangeMode;
      parm.rangeidx = WaterTankSysControl2024_P.AnalogOutput1_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &WaterTankSysControl2024_P.AnalogOutput1_Channels, ((real_T*)
        (&WaterTankSysControl2024_B.ActualInput)), &parm);
    }
  }

  /* S-Function (sldrtao): '<S3>/Analog Output2' */
  /* S-Function Block: <S3>/Analog Output2 */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) WaterTankSysControl2024_P.AnalogOutput2_RangeMode;
      parm.rangeidx = WaterTankSysControl2024_P.AnalogOutput2_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &WaterTankSysControl2024_P.AnalogOutput2_Channels, ((real_T*)
        (&rtb_SaturationTANK4)), &parm);
    }
  }
}

/* Model update function for TID0 */
void WaterTankSysControl2024_update0(void) /* Sample time: [0.75s, 0.0s] */
{
  /* Update for DiscreteFir: '<S3>/Discrete FIR Filter1' */
  /* Update circular buffer index */
  WaterTankSysControl2024_DW.DiscreteFIRFilter1_circBuf--;
  if (WaterTankSysControl2024_DW.DiscreteFIRFilter1_circBuf < 0) {
    WaterTankSysControl2024_DW.DiscreteFIRFilter1_circBuf = 3;
  }

  /* Update circular buffer */
  WaterTankSysControl2024_DW.DiscreteFIRFilter1_states[WaterTankSysControl2024_DW.DiscreteFIRFilter1_circBuf]
    = WaterTankSysControl2024_B.OriginalOutput;

  /* End of Update for DiscreteFir: '<S3>/Discrete FIR Filter1' */

  /* Update for Delay: '<S1>/Delay' */
  WaterTankSysControl2024_DW.Delay_DSTATE[0] = WaterTankSysControl2024_B.Sum1[0];
  WaterTankSysControl2024_DW.Delay_DSTATE[1] = WaterTankSysControl2024_B.Sum1[1];

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++WaterTankSysControl2024_M->Timing.clockTick0)) {
    ++WaterTankSysControl2024_M->Timing.clockTickH0;
  }

  WaterTankSysControl2024_M->Timing.t[0] =
    WaterTankSysControl2024_M->Timing.clockTick0 *
    WaterTankSysControl2024_M->Timing.stepSize0 +
    WaterTankSysControl2024_M->Timing.clockTickH0 *
    WaterTankSysControl2024_M->Timing.stepSize0 * 4294967296.0;
}

/* Model output function for TID1 */
void WaterTankSysControl2024_output1(void) /* Sample time: [105.0s, 0.0s] */
{
  real_T rtb_Output;
  uint8_T rtb_FixPtSum1;

  /* MultiPortSwitch: '<S2>/Output' incorporates:
   *  Constant: '<S2>/Vector'
   *  UnitDelay: '<S4>/Output'
   */
  rtb_Output =
    WaterTankSysControl2024_P.RepeatingSequenceStair1_OutValues[WaterTankSysControl2024_DW.Output_DSTATE];

  /* RateTransition: '<Root>/Rate Transition1' */
  WaterTankSysControl2024_DW.RateTransition1_Buffer0 = rtb_Output;

  /* Sum: '<S5>/FixPt Sum1' incorporates:
   *  Constant: '<S5>/FixPt Constant'
   *  UnitDelay: '<S4>/Output'
   */
  rtb_FixPtSum1 = (uint8_T)(WaterTankSysControl2024_DW.Output_DSTATE +
    WaterTankSysControl2024_P.FixPtConstant_Value);

  /* Switch: '<S6>/FixPt Switch' */
  if (rtb_FixPtSum1 > WaterTankSysControl2024_P.LimitedCounter_uplimit) {
    /* Switch: '<S6>/FixPt Switch' incorporates:
     *  Constant: '<S6>/Constant'
     */
    WaterTankSysControl2024_B.FixPtSwitch =
      WaterTankSysControl2024_P.Constant_Value;
  } else {
    /* Switch: '<S6>/FixPt Switch' */
    WaterTankSysControl2024_B.FixPtSwitch = rtb_FixPtSum1;
  }

  /* End of Switch: '<S6>/FixPt Switch' */
}

/* Model update function for TID1 */
void WaterTankSysControl2024_update1(void) /* Sample time: [105.0s, 0.0s] */
{
  /* Update for UnitDelay: '<S4>/Output' */
  WaterTankSysControl2024_DW.Output_DSTATE =
    WaterTankSysControl2024_B.FixPtSwitch;

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick1"
   * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++WaterTankSysControl2024_M->Timing.clockTick1)) {
    ++WaterTankSysControl2024_M->Timing.clockTickH1;
  }

  WaterTankSysControl2024_M->Timing.t[1] =
    WaterTankSysControl2024_M->Timing.clockTick1 *
    WaterTankSysControl2024_M->Timing.stepSize1 +
    WaterTankSysControl2024_M->Timing.clockTickH1 *
    WaterTankSysControl2024_M->Timing.stepSize1 * 4294967296.0;
}

/* Use this function only if you need to maintain compatibility with an existing static main program. */
void WaterTankSysControl2024_output(int_T tid)
{
  switch (tid) {
   case 0 :
    WaterTankSysControl2024_output0();
    break;

   case 1 :
    WaterTankSysControl2024_output1();
    break;

   default :
    /* do nothing */
    break;
  }
}

/* Use this function only if you need to maintain compatibility with an existing static main program. */
void WaterTankSysControl2024_update(int_T tid)
{
  switch (tid) {
   case 0 :
    WaterTankSysControl2024_update0();
    break;

   case 1 :
    WaterTankSysControl2024_update1();
    break;

   default :
    /* do nothing */
    break;
  }
}

/* Model initialize function */
void WaterTankSysControl2024_initialize(void)
{
  /* Start for RateTransition: '<Root>/Rate Transition1' */
  WaterTankSysControl2024_B.OffsetFreeReferenceSignaly_refk =
    WaterTankSysControl2024_P.RateTransition1_InitialCondition;

  /* Start for S-Function (sldrtao): '<S3>/Analog Output1' */

  /* S-Function Block: <S3>/Analog Output1 */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) WaterTankSysControl2024_P.AnalogOutput1_RangeMode;
      parm.rangeidx = WaterTankSysControl2024_P.AnalogOutput1_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &WaterTankSysControl2024_P.AnalogOutput1_Channels,
                     &WaterTankSysControl2024_P.AnalogOutput1_InitialValue,
                     &parm);
    }
  }

  /* Start for S-Function (sldrtao): '<S3>/Analog Output2' */

  /* S-Function Block: <S3>/Analog Output2 */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) WaterTankSysControl2024_P.AnalogOutput2_RangeMode;
      parm.rangeidx = WaterTankSysControl2024_P.AnalogOutput2_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &WaterTankSysControl2024_P.AnalogOutput2_Channels,
                     &WaterTankSysControl2024_P.AnalogOutput2_InitialValue,
                     &parm);
    }
  }

  /* InitializeConditions for RateTransition: '<Root>/Rate Transition1' */
  WaterTankSysControl2024_DW.RateTransition1_Buffer0 =
    WaterTankSysControl2024_P.RateTransition1_InitialCondition;

  /* InitializeConditions for DiscreteFir: '<S3>/Discrete FIR Filter1' */
  WaterTankSysControl2024_DW.DiscreteFIRFilter1_circBuf = 0;
  WaterTankSysControl2024_DW.DiscreteFIRFilter1_states[0] =
    WaterTankSysControl2024_P.DiscreteFIRFilter1_InitialStates;
  WaterTankSysControl2024_DW.DiscreteFIRFilter1_states[1] =
    WaterTankSysControl2024_P.DiscreteFIRFilter1_InitialStates;
  WaterTankSysControl2024_DW.DiscreteFIRFilter1_states[2] =
    WaterTankSysControl2024_P.DiscreteFIRFilter1_InitialStates;
  WaterTankSysControl2024_DW.DiscreteFIRFilter1_states[3] =
    WaterTankSysControl2024_P.DiscreteFIRFilter1_InitialStates;

  /* InitializeConditions for Delay: '<S1>/Delay' */
  WaterTankSysControl2024_DW.Delay_DSTATE[0] =
    WaterTankSysControl2024_P.Delay_InitialCondition[0];
  WaterTankSysControl2024_DW.Delay_DSTATE[1] =
    WaterTankSysControl2024_P.Delay_InitialCondition[1];

  /* InitializeConditions for UnitDelay: '<S4>/Output' */
  WaterTankSysControl2024_DW.Output_DSTATE =
    WaterTankSysControl2024_P.Output_InitialCondition;
}

/* Model terminate function */
void WaterTankSysControl2024_terminate(void)
{
  /* Terminate for S-Function (sldrtao): '<S3>/Analog Output1' */

  /* S-Function Block: <S3>/Analog Output1 */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) WaterTankSysControl2024_P.AnalogOutput1_RangeMode;
      parm.rangeidx = WaterTankSysControl2024_P.AnalogOutput1_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &WaterTankSysControl2024_P.AnalogOutput1_Channels,
                     &WaterTankSysControl2024_P.AnalogOutput1_FinalValue, &parm);
    }
  }

  /* Terminate for S-Function (sldrtao): '<S3>/Analog Output2' */

  /* S-Function Block: <S3>/Analog Output2 */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) WaterTankSysControl2024_P.AnalogOutput2_RangeMode;
      parm.rangeidx = WaterTankSysControl2024_P.AnalogOutput2_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &WaterTankSysControl2024_P.AnalogOutput2_Channels,
                     &WaterTankSysControl2024_P.AnalogOutput2_FinalValue, &parm);
    }
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  WaterTankSysControl2024_output(tid);
}

void MdlUpdate(int_T tid)
{
  WaterTankSysControl2024_update(tid);
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
  WaterTankSysControl2024_initialize();
}

void MdlTerminate(void)
{
  WaterTankSysControl2024_terminate();
}

/* Registration function */
RT_MODEL_WaterTankSysControl2024_T *WaterTankSysControl2024(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)WaterTankSysControl2024_M, 0,
                sizeof(RT_MODEL_WaterTankSysControl2024_T));

  /* Initialize timing info */
  {
    int_T *mdlTsMap = WaterTankSysControl2024_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "WaterTankSysControl2024_M points to
       static memory which is guaranteed to be non-NULL" */
    WaterTankSysControl2024_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    WaterTankSysControl2024_M->Timing.sampleTimes =
      (&WaterTankSysControl2024_M->Timing.sampleTimesArray[0]);
    WaterTankSysControl2024_M->Timing.offsetTimes =
      (&WaterTankSysControl2024_M->Timing.offsetTimesArray[0]);

    /* task periods */
    WaterTankSysControl2024_M->Timing.sampleTimes[0] = (0.75);
    WaterTankSysControl2024_M->Timing.sampleTimes[1] = (105.0);

    /* task offsets */
    WaterTankSysControl2024_M->Timing.offsetTimes[0] = (0.0);
    WaterTankSysControl2024_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(WaterTankSysControl2024_M,
             &WaterTankSysControl2024_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = WaterTankSysControl2024_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits =
      WaterTankSysControl2024_M->Timing.perTaskSampleHitsArray;
    WaterTankSysControl2024_M->Timing.perTaskSampleHits =
      (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    WaterTankSysControl2024_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(WaterTankSysControl2024_M, 525.0);
  WaterTankSysControl2024_M->Timing.stepSize0 = 0.75;
  WaterTankSysControl2024_M->Timing.stepSize1 = 105.0;

  /* External mode info */
  WaterTankSysControl2024_M->Sizes.checksums[0] = (1658457588U);
  WaterTankSysControl2024_M->Sizes.checksums[1] = (1553399214U);
  WaterTankSysControl2024_M->Sizes.checksums[2] = (2898911741U);
  WaterTankSysControl2024_M->Sizes.checksums[3] = (2528487444U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    WaterTankSysControl2024_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(WaterTankSysControl2024_M->extModeInfo,
      &WaterTankSysControl2024_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(WaterTankSysControl2024_M->extModeInfo,
                        WaterTankSysControl2024_M->Sizes.checksums);
    rteiSetTPtr(WaterTankSysControl2024_M->extModeInfo, rtmGetTPtr
                (WaterTankSysControl2024_M));
  }

  WaterTankSysControl2024_M->solverInfoPtr =
    (&WaterTankSysControl2024_M->solverInfo);
  WaterTankSysControl2024_M->Timing.stepSize = (0.75);
  rtsiSetFixedStepSize(&WaterTankSysControl2024_M->solverInfo, 0.75);
  rtsiSetSolverMode(&WaterTankSysControl2024_M->solverInfo,
                    SOLVER_MODE_MULTITASKING);

  /* block I/O */
  WaterTankSysControl2024_M->blockIO = ((void *) &WaterTankSysControl2024_B);
  (void) memset(((void *) &WaterTankSysControl2024_B), 0,
                sizeof(B_WaterTankSysControl2024_T));

  /* parameters */
  WaterTankSysControl2024_M->defaultParam = ((real_T *)
    &WaterTankSysControl2024_P);

  /* states (dwork) */
  WaterTankSysControl2024_M->dwork = ((void *) &WaterTankSysControl2024_DW);
  (void) memset((void *)&WaterTankSysControl2024_DW, 0,
                sizeof(DW_WaterTankSysControl2024_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    WaterTankSysControl2024_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 23;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  WaterTankSysControl2024_M->Sizes.numContStates = (0);/* Number of continuous states */
  WaterTankSysControl2024_M->Sizes.numY = (0);/* Number of model outputs */
  WaterTankSysControl2024_M->Sizes.numU = (0);/* Number of model inputs */
  WaterTankSysControl2024_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  WaterTankSysControl2024_M->Sizes.numSampTimes = (2);/* Number of sample times */
  WaterTankSysControl2024_M->Sizes.numBlocks = (35);/* Number of blocks */
  WaterTankSysControl2024_M->Sizes.numBlockIO = (7);/* Number of block outputs */
  WaterTankSysControl2024_M->Sizes.numBlockPrms = (62);/* Sum of parameter "widths" */
  return WaterTankSysControl2024_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
