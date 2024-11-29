/*
 * WaterTankSysControlPID2024.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "WaterTankSysControlPID2024".
 *
 * Model version              : 9.8
 * Simulink Coder version : 23.2 (R2023b) 01-Aug-2023
 * C source code generated on : Mon Nov 18 17:27:55 2024
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "WaterTankSysControlPID2024.h"
#include "rtwtypes.h"
#include <string.h>
#include "rt_nonfinite.h"
#include "WaterTankSysControlPID2024_dt.h"

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
B_WaterTankSysControlPID2024_T WaterTankSysControlPID2024_B;

/* Block states (default storage) */
DW_WaterTankSysControlPID2024_T WaterTankSysControlPID2024_DW;

/* Real-time model */
static RT_MODEL_WaterTankSysControlPID2024_T WaterTankSysControlPID2024_M_;
RT_MODEL_WaterTankSysControlPID2024_T *const WaterTankSysControlPID2024_M =
  &WaterTankSysControlPID2024_M_;
static void rate_monotonic_scheduler(void);
time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
{
  rtmSampleHitPtr[1] = rtmStepTask(WaterTankSysControlPID2024_M, 1);
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
  WaterTankSysControlPID2024_M->Timing.RateInteraction.TID0_1 =
    (WaterTankSysControlPID2024_M->Timing.TaskCounters.TID[1] == 0);

  /* update PerTaskSampleHits matrix for non-inline sfcn */
  WaterTankSysControlPID2024_M->Timing.perTaskSampleHits[1] =
    WaterTankSysControlPID2024_M->Timing.RateInteraction.TID0_1;

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (WaterTankSysControlPID2024_M->Timing.TaskCounters.TID[1])++;
  if ((WaterTankSysControlPID2024_M->Timing.TaskCounters.TID[1]) > 139) {/* Sample time: [105.0s, 0.0s] */
    WaterTankSysControlPID2024_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Model output function for TID0 */
void WaterTankSysControlPID2024_output0(void) /* Sample time: [0.75s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_OriginalOutput;
  real_T rtb_SaturationTANK2;
  real_T rtb_Sum6;
  real_T u0;
  int32_T cff;
  int32_T j;

  {                                    /* Sample time: [0.75s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* RateTransition: '<Root>/Rate Transition2' */
  if (WaterTankSysControlPID2024_M->Timing.RateInteraction.TID0_1) {
    /* RateTransition: '<Root>/Rate Transition2' */
    WaterTankSysControlPID2024_B.OffsetFreeReferenceSignaly_refk =
      WaterTankSysControlPID2024_DW.RateTransition2_Buffer0;
  }

  /* End of RateTransition: '<Root>/Rate Transition2' */

  /* Sum: '<Root>/Sum7' incorporates:
   *  Constant: '<Root>/Constant5'
   */
  WaterTankSysControlPID2024_B.ReferenceSignal =
    WaterTankSysControlPID2024_P.y_offset +
    WaterTankSysControlPID2024_B.OffsetFreeReferenceSignaly_refk;

  /* S-Function (sldrtai): '<S3>/Analog Input1' */
  /* S-Function Block: <S3>/Analog Input1 */
  {
    ANALOGIOPARM parm;
    parm.mode = (RANGEMODE) WaterTankSysControlPID2024_P.AnalogInput1_RangeMode;
    parm.rangeidx = WaterTankSysControlPID2024_P.AnalogInput1_VoltRange;
    RTBIO_DriverIO(0, ANALOGINPUT, IOREAD, 1,
                   &WaterTankSysControlPID2024_P.AnalogInput1_Channels,
                   &WaterTankSysControlPID2024_B.OriginalOutput, &parm);
  }

  /* S-Function (sldrtai): '<S3>/Analog Input2' */
  /* S-Function Block: <S3>/Analog Input2 */
  {
    ANALOGIOPARM parm;
    parm.mode = (RANGEMODE) WaterTankSysControlPID2024_P.AnalogInput2_RangeMode;
    parm.rangeidx = WaterTankSysControlPID2024_P.AnalogInput2_VoltRange;
    RTBIO_DriverIO(0, ANALOGINPUT, IOREAD, 1,
                   &WaterTankSysControlPID2024_P.AnalogInput2_Channels,
                   &rtb_OriginalOutput, &parm);
  }

  /* DiscreteFir: '<S3>/Discrete FIR Filter1' */
  rtb_Sum6 = WaterTankSysControlPID2024_B.OriginalOutput *
    WaterTankSysControlPID2024_P.DiscreteFIRFilter1_Coefficients[0];
  cff = 1;
  for (j = WaterTankSysControlPID2024_DW.DiscreteFIRFilter1_circBuf; j < 4; j++)
  {
    rtb_Sum6 += WaterTankSysControlPID2024_DW.DiscreteFIRFilter1_states[j] *
      WaterTankSysControlPID2024_P.DiscreteFIRFilter1_Coefficients[cff];
    cff++;
  }

  for (j = 0; j < WaterTankSysControlPID2024_DW.DiscreteFIRFilter1_circBuf; j++)
  {
    rtb_Sum6 += WaterTankSysControlPID2024_DW.DiscreteFIRFilter1_states[j] *
      WaterTankSysControlPID2024_P.DiscreteFIRFilter1_Coefficients[cff];
    cff++;
  }

  /* DiscreteFir: '<S3>/Discrete FIR Filter1' */
  WaterTankSysControlPID2024_B.NoiseReducedOutput = rtb_Sum6;

  /* Sum: '<Root>/Sum6' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Sum: '<Root>/Sum8'
   */
  rtb_Sum6 = WaterTankSysControlPID2024_B.OffsetFreeReferenceSignaly_refk -
    (WaterTankSysControlPID2024_B.NoiseReducedOutput -
     WaterTankSysControlPID2024_P.y_offset);

  /* Gain: '<S38>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S30>/Filter'
   *  Gain: '<S29>/Derivative Gain'
   *  Sum: '<S30>/SumD'
   */
  WaterTankSysControlPID2024_B.FilterCoefficient =
    (WaterTankSysControlPID2024_P.DiscretePIDController_D * rtb_Sum6 -
     WaterTankSysControlPID2024_DW.Filter_DSTATE) *
    WaterTankSysControlPID2024_P.DiscretePIDController_N;

  /* Sum: '<Root>/Sum2' incorporates:
   *  Constant: '<Root>/Constant4'
   *  DiscreteIntegrator: '<S35>/Integrator'
   *  Gain: '<S40>/Proportional Gain'
   *  Sum: '<S44>/Sum'
   */
  rtb_SaturationTANK2 = ((WaterTankSysControlPID2024_P.DiscretePIDController_P *
    rtb_Sum6 + WaterTankSysControlPID2024_DW.Integrator_DSTATE) +
    WaterTankSysControlPID2024_B.FilterCoefficient) +
    WaterTankSysControlPID2024_P.u_offset;

  /* Gain: '<Root>/Activation Gain TANK#1' */
  u0 = WaterTankSysControlPID2024_P.ActivationGainTANK1_Gain *
    rtb_SaturationTANK2;

  /* Saturate: '<Root>/Saturation TANK#1' */
  if (u0 > WaterTankSysControlPID2024_P.SaturationTANK1_UpperSat) {
    /* Saturate: '<Root>/Saturation TANK#1' */
    WaterTankSysControlPID2024_B.ActualInput =
      WaterTankSysControlPID2024_P.SaturationTANK1_UpperSat;
  } else if (u0 < WaterTankSysControlPID2024_P.SaturationTANK1_LowerSat) {
    /* Saturate: '<Root>/Saturation TANK#1' */
    WaterTankSysControlPID2024_B.ActualInput =
      WaterTankSysControlPID2024_P.SaturationTANK1_LowerSat;
  } else {
    /* Saturate: '<Root>/Saturation TANK#1' */
    WaterTankSysControlPID2024_B.ActualInput = u0;
  }

  /* End of Saturate: '<Root>/Saturation TANK#1' */
  /* Gain: '<S32>/Integral Gain' */
  WaterTankSysControlPID2024_B.IntegralGain =
    WaterTankSysControlPID2024_P.DiscretePIDController_I * rtb_Sum6;

  /* Gain: '<Root>/Activation Gain TANK#2' */
  rtb_SaturationTANK2 *= WaterTankSysControlPID2024_P.ActivationGainTANK2_Gain;

  /* Saturate: '<Root>/Saturation TANK#2' */
  if (rtb_SaturationTANK2 >
      WaterTankSysControlPID2024_P.SaturationTANK2_UpperSat) {
    rtb_SaturationTANK2 = WaterTankSysControlPID2024_P.SaturationTANK2_UpperSat;
  } else if (rtb_SaturationTANK2 <
             WaterTankSysControlPID2024_P.SaturationTANK2_LowerSat) {
    rtb_SaturationTANK2 = WaterTankSysControlPID2024_P.SaturationTANK2_LowerSat;
  }

  /* End of Saturate: '<Root>/Saturation TANK#2' */

  /* S-Function (sldrtao): '<S3>/Analog Output1' */
  /* S-Function Block: <S3>/Analog Output1 */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE)
        WaterTankSysControlPID2024_P.AnalogOutput1_RangeMode;
      parm.rangeidx = WaterTankSysControlPID2024_P.AnalogOutput1_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &WaterTankSysControlPID2024_P.AnalogOutput1_Channels,
                     ((real_T*) (&WaterTankSysControlPID2024_B.ActualInput)),
                     &parm);
    }
  }

  /* S-Function (sldrtao): '<S3>/Analog Output2' */
  /* S-Function Block: <S3>/Analog Output2 */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE)
        WaterTankSysControlPID2024_P.AnalogOutput2_RangeMode;
      parm.rangeidx = WaterTankSysControlPID2024_P.AnalogOutput2_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &WaterTankSysControlPID2024_P.AnalogOutput2_Channels,
                     ((real_T*) (&rtb_SaturationTANK2)), &parm);
    }
  }
}

/* Model update function for TID0 */
void WaterTankSysControlPID2024_update0(void) /* Sample time: [0.75s, 0.0s] */
{
  /* Update for DiscreteFir: '<S3>/Discrete FIR Filter1' */
  /* Update circular buffer index */
  WaterTankSysControlPID2024_DW.DiscreteFIRFilter1_circBuf--;
  if (WaterTankSysControlPID2024_DW.DiscreteFIRFilter1_circBuf < 0) {
    WaterTankSysControlPID2024_DW.DiscreteFIRFilter1_circBuf = 3;
  }

  /* Update circular buffer */
  WaterTankSysControlPID2024_DW.DiscreteFIRFilter1_states[WaterTankSysControlPID2024_DW.DiscreteFIRFilter1_circBuf]
    = WaterTankSysControlPID2024_B.OriginalOutput;

  /* End of Update for DiscreteFir: '<S3>/Discrete FIR Filter1' */

  /* Update for DiscreteIntegrator: '<S35>/Integrator' */
  WaterTankSysControlPID2024_DW.Integrator_DSTATE +=
    WaterTankSysControlPID2024_P.Integrator_gainval *
    WaterTankSysControlPID2024_B.IntegralGain;

  /* Update for DiscreteIntegrator: '<S30>/Filter' */
  WaterTankSysControlPID2024_DW.Filter_DSTATE +=
    WaterTankSysControlPID2024_P.Filter_gainval *
    WaterTankSysControlPID2024_B.FilterCoefficient;

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++WaterTankSysControlPID2024_M->Timing.clockTick0)) {
    ++WaterTankSysControlPID2024_M->Timing.clockTickH0;
  }

  WaterTankSysControlPID2024_M->Timing.t[0] =
    WaterTankSysControlPID2024_M->Timing.clockTick0 *
    WaterTankSysControlPID2024_M->Timing.stepSize0 +
    WaterTankSysControlPID2024_M->Timing.clockTickH0 *
    WaterTankSysControlPID2024_M->Timing.stepSize0 * 4294967296.0;
}

/* Model output function for TID1 */
void WaterTankSysControlPID2024_output1(void) /* Sample time: [105.0s, 0.0s] */
{
  real_T rtb_Output;
  uint8_T rtb_FixPtSum1;

  /* MultiPortSwitch: '<S2>/Output' incorporates:
   *  Constant: '<S2>/Vector'
   *  UnitDelay: '<S52>/Output'
   */
  rtb_Output =
    WaterTankSysControlPID2024_P.RepeatingSequenceStair2_OutValues[WaterTankSysControlPID2024_DW.Output_DSTATE];

  /* RateTransition: '<Root>/Rate Transition2' */
  WaterTankSysControlPID2024_DW.RateTransition2_Buffer0 = rtb_Output;

  /* Sum: '<S53>/FixPt Sum1' incorporates:
   *  Constant: '<S53>/FixPt Constant'
   *  UnitDelay: '<S52>/Output'
   */
  rtb_FixPtSum1 = (uint8_T)(WaterTankSysControlPID2024_DW.Output_DSTATE +
    WaterTankSysControlPID2024_P.FixPtConstant_Value);

  /* Switch: '<S54>/FixPt Switch' */
  if (rtb_FixPtSum1 > WaterTankSysControlPID2024_P.LimitedCounter_uplimit) {
    /* Switch: '<S54>/FixPt Switch' incorporates:
     *  Constant: '<S54>/Constant'
     */
    WaterTankSysControlPID2024_B.FixPtSwitch =
      WaterTankSysControlPID2024_P.Constant_Value;
  } else {
    /* Switch: '<S54>/FixPt Switch' */
    WaterTankSysControlPID2024_B.FixPtSwitch = rtb_FixPtSum1;
  }

  /* End of Switch: '<S54>/FixPt Switch' */
}

/* Model update function for TID1 */
void WaterTankSysControlPID2024_update1(void) /* Sample time: [105.0s, 0.0s] */
{
  /* Update for UnitDelay: '<S52>/Output' */
  WaterTankSysControlPID2024_DW.Output_DSTATE =
    WaterTankSysControlPID2024_B.FixPtSwitch;

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick1"
   * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++WaterTankSysControlPID2024_M->Timing.clockTick1)) {
    ++WaterTankSysControlPID2024_M->Timing.clockTickH1;
  }

  WaterTankSysControlPID2024_M->Timing.t[1] =
    WaterTankSysControlPID2024_M->Timing.clockTick1 *
    WaterTankSysControlPID2024_M->Timing.stepSize1 +
    WaterTankSysControlPID2024_M->Timing.clockTickH1 *
    WaterTankSysControlPID2024_M->Timing.stepSize1 * 4294967296.0;
}

/* Use this function only if you need to maintain compatibility with an existing static main program. */
void WaterTankSysControlPID2024_output(int_T tid)
{
  switch (tid) {
   case 0 :
    WaterTankSysControlPID2024_output0();
    break;

   case 1 :
    WaterTankSysControlPID2024_output1();
    break;

   default :
    /* do nothing */
    break;
  }
}

/* Use this function only if you need to maintain compatibility with an existing static main program. */
void WaterTankSysControlPID2024_update(int_T tid)
{
  switch (tid) {
   case 0 :
    WaterTankSysControlPID2024_update0();
    break;

   case 1 :
    WaterTankSysControlPID2024_update1();
    break;

   default :
    /* do nothing */
    break;
  }
}

/* Model initialize function */
void WaterTankSysControlPID2024_initialize(void)
{
  /* Start for RateTransition: '<Root>/Rate Transition2' */
  WaterTankSysControlPID2024_B.OffsetFreeReferenceSignaly_refk =
    WaterTankSysControlPID2024_P.RateTransition2_InitialCondition;

  /* Start for S-Function (sldrtao): '<S3>/Analog Output1' */

  /* S-Function Block: <S3>/Analog Output1 */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE)
        WaterTankSysControlPID2024_P.AnalogOutput1_RangeMode;
      parm.rangeidx = WaterTankSysControlPID2024_P.AnalogOutput1_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &WaterTankSysControlPID2024_P.AnalogOutput1_Channels,
                     &WaterTankSysControlPID2024_P.AnalogOutput1_InitialValue,
                     &parm);
    }
  }

  /* Start for S-Function (sldrtao): '<S3>/Analog Output2' */

  /* S-Function Block: <S3>/Analog Output2 */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE)
        WaterTankSysControlPID2024_P.AnalogOutput2_RangeMode;
      parm.rangeidx = WaterTankSysControlPID2024_P.AnalogOutput2_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &WaterTankSysControlPID2024_P.AnalogOutput2_Channels,
                     &WaterTankSysControlPID2024_P.AnalogOutput2_InitialValue,
                     &parm);
    }
  }

  /* InitializeConditions for RateTransition: '<Root>/Rate Transition2' */
  WaterTankSysControlPID2024_DW.RateTransition2_Buffer0 =
    WaterTankSysControlPID2024_P.RateTransition2_InitialCondition;

  /* InitializeConditions for DiscreteFir: '<S3>/Discrete FIR Filter1' */
  WaterTankSysControlPID2024_DW.DiscreteFIRFilter1_circBuf = 0;
  WaterTankSysControlPID2024_DW.DiscreteFIRFilter1_states[0] =
    WaterTankSysControlPID2024_P.DiscreteFIRFilter1_InitialStates;
  WaterTankSysControlPID2024_DW.DiscreteFIRFilter1_states[1] =
    WaterTankSysControlPID2024_P.DiscreteFIRFilter1_InitialStates;
  WaterTankSysControlPID2024_DW.DiscreteFIRFilter1_states[2] =
    WaterTankSysControlPID2024_P.DiscreteFIRFilter1_InitialStates;
  WaterTankSysControlPID2024_DW.DiscreteFIRFilter1_states[3] =
    WaterTankSysControlPID2024_P.DiscreteFIRFilter1_InitialStates;

  /* InitializeConditions for DiscreteIntegrator: '<S35>/Integrator' */
  WaterTankSysControlPID2024_DW.Integrator_DSTATE =
    WaterTankSysControlPID2024_P.DiscretePIDController_InitialConditionForIntegrator;

  /* InitializeConditions for DiscreteIntegrator: '<S30>/Filter' */
  WaterTankSysControlPID2024_DW.Filter_DSTATE =
    WaterTankSysControlPID2024_P.DiscretePIDController_InitialConditionForFilter;

  /* InitializeConditions for UnitDelay: '<S52>/Output' */
  WaterTankSysControlPID2024_DW.Output_DSTATE =
    WaterTankSysControlPID2024_P.Output_InitialCondition;
}

/* Model terminate function */
void WaterTankSysControlPID2024_terminate(void)
{
  /* Terminate for S-Function (sldrtao): '<S3>/Analog Output1' */

  /* S-Function Block: <S3>/Analog Output1 */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE)
        WaterTankSysControlPID2024_P.AnalogOutput1_RangeMode;
      parm.rangeidx = WaterTankSysControlPID2024_P.AnalogOutput1_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &WaterTankSysControlPID2024_P.AnalogOutput1_Channels,
                     &WaterTankSysControlPID2024_P.AnalogOutput1_FinalValue,
                     &parm);
    }
  }

  /* Terminate for S-Function (sldrtao): '<S3>/Analog Output2' */

  /* S-Function Block: <S3>/Analog Output2 */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE)
        WaterTankSysControlPID2024_P.AnalogOutput2_RangeMode;
      parm.rangeidx = WaterTankSysControlPID2024_P.AnalogOutput2_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &WaterTankSysControlPID2024_P.AnalogOutput2_Channels,
                     &WaterTankSysControlPID2024_P.AnalogOutput2_FinalValue,
                     &parm);
    }
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  WaterTankSysControlPID2024_output(tid);
}

void MdlUpdate(int_T tid)
{
  WaterTankSysControlPID2024_update(tid);
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
  WaterTankSysControlPID2024_initialize();
}

void MdlTerminate(void)
{
  WaterTankSysControlPID2024_terminate();
}

/* Registration function */
RT_MODEL_WaterTankSysControlPID2024_T *WaterTankSysControlPID2024(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)WaterTankSysControlPID2024_M, 0,
                sizeof(RT_MODEL_WaterTankSysControlPID2024_T));

  /* Initialize timing info */
  {
    int_T *mdlTsMap = WaterTankSysControlPID2024_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "WaterTankSysControlPID2024_M points to
       static memory which is guaranteed to be non-NULL" */
    WaterTankSysControlPID2024_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    WaterTankSysControlPID2024_M->Timing.sampleTimes =
      (&WaterTankSysControlPID2024_M->Timing.sampleTimesArray[0]);
    WaterTankSysControlPID2024_M->Timing.offsetTimes =
      (&WaterTankSysControlPID2024_M->Timing.offsetTimesArray[0]);

    /* task periods */
    WaterTankSysControlPID2024_M->Timing.sampleTimes[0] = (0.75);
    WaterTankSysControlPID2024_M->Timing.sampleTimes[1] = (105.0);

    /* task offsets */
    WaterTankSysControlPID2024_M->Timing.offsetTimes[0] = (0.0);
    WaterTankSysControlPID2024_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(WaterTankSysControlPID2024_M,
             &WaterTankSysControlPID2024_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = WaterTankSysControlPID2024_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits =
      WaterTankSysControlPID2024_M->Timing.perTaskSampleHitsArray;
    WaterTankSysControlPID2024_M->Timing.perTaskSampleHits =
      (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    WaterTankSysControlPID2024_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(WaterTankSysControlPID2024_M, 525.0);
  WaterTankSysControlPID2024_M->Timing.stepSize0 = 0.75;
  WaterTankSysControlPID2024_M->Timing.stepSize1 = 105.0;

  /* External mode info */
  WaterTankSysControlPID2024_M->Sizes.checksums[0] = (2347065568U);
  WaterTankSysControlPID2024_M->Sizes.checksums[1] = (732899827U);
  WaterTankSysControlPID2024_M->Sizes.checksums[2] = (2651693347U);
  WaterTankSysControlPID2024_M->Sizes.checksums[3] = (506103482U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    WaterTankSysControlPID2024_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(WaterTankSysControlPID2024_M->extModeInfo,
      &WaterTankSysControlPID2024_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(WaterTankSysControlPID2024_M->extModeInfo,
                        WaterTankSysControlPID2024_M->Sizes.checksums);
    rteiSetTPtr(WaterTankSysControlPID2024_M->extModeInfo, rtmGetTPtr
                (WaterTankSysControlPID2024_M));
  }

  WaterTankSysControlPID2024_M->solverInfoPtr =
    (&WaterTankSysControlPID2024_M->solverInfo);
  WaterTankSysControlPID2024_M->Timing.stepSize = (0.75);
  rtsiSetFixedStepSize(&WaterTankSysControlPID2024_M->solverInfo, 0.75);
  rtsiSetSolverMode(&WaterTankSysControlPID2024_M->solverInfo,
                    SOLVER_MODE_MULTITASKING);

  /* block I/O */
  WaterTankSysControlPID2024_M->blockIO = ((void *)
    &WaterTankSysControlPID2024_B);
  (void) memset(((void *) &WaterTankSysControlPID2024_B), 0,
                sizeof(B_WaterTankSysControlPID2024_T));

  /* parameters */
  WaterTankSysControlPID2024_M->defaultParam = ((real_T *)
    &WaterTankSysControlPID2024_P);

  /* states (dwork) */
  WaterTankSysControlPID2024_M->dwork = ((void *) &WaterTankSysControlPID2024_DW);
  (void) memset((void *)&WaterTankSysControlPID2024_DW, 0,
                sizeof(DW_WaterTankSysControlPID2024_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    WaterTankSysControlPID2024_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 23;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  WaterTankSysControlPID2024_M->Sizes.numContStates = (0);/* Number of continuous states */
  WaterTankSysControlPID2024_M->Sizes.numY = (0);/* Number of model outputs */
  WaterTankSysControlPID2024_M->Sizes.numU = (0);/* Number of model inputs */
  WaterTankSysControlPID2024_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  WaterTankSysControlPID2024_M->Sizes.numSampTimes = (2);/* Number of sample times */
  WaterTankSysControlPID2024_M->Sizes.numBlocks = (34);/* Number of blocks */
  WaterTankSysControlPID2024_M->Sizes.numBlockIO = (8);/* Number of block outputs */
  WaterTankSysControlPID2024_M->Sizes.numBlockPrms = (55);/* Sum of parameter "widths" */
  return WaterTankSysControlPID2024_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
