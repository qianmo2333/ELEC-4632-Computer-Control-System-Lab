    function targMap = targDataMap(),

    ;%***********************
    ;% Create Parameter Map *
    ;%***********************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 5;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc paramMap
        ;%
        paramMap.nSections           = nTotSects;
        paramMap.sectIdxOffset       = sectIdxOffset;
            paramMap.sections(nTotSects) = dumSection; %prealloc
        paramMap.nTotData            = -1;

        ;%
        ;% Auto data (WaterTankSysControl2024_P)
        ;%
            section.nData     = 21;
            section.data(21)  = dumData; %prealloc

                    ;% WaterTankSysControl2024_P.C_obs
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% WaterTankSysControl2024_P.G_obs
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 2;

                    ;% WaterTankSysControl2024_P.Gcl_1
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 6;

                    ;% WaterTankSysControl2024_P.H_obs
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 7;

                    ;% WaterTankSysControl2024_P.K
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 9;

                    ;% WaterTankSysControl2024_P.L
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 11;

                    ;% WaterTankSysControl2024_P.u_offset
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 13;

                    ;% WaterTankSysControl2024_P.y_offset
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 14;

                    ;% WaterTankSysControl2024_P.AnalogOutput1_FinalValue
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 15;

                    ;% WaterTankSysControl2024_P.AnalogOutput2_FinalValue
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 16;

                    ;% WaterTankSysControl2024_P.AnalogOutput1_InitialValue
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 17;

                    ;% WaterTankSysControl2024_P.AnalogOutput2_InitialValue
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 18;

                    ;% WaterTankSysControl2024_P.AnalogInput1_MaxMissedTicks
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 19;

                    ;% WaterTankSysControl2024_P.AnalogInput2_MaxMissedTicks
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 20;

                    ;% WaterTankSysControl2024_P.AnalogOutput1_MaxMissedTicks
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 21;

                    ;% WaterTankSysControl2024_P.AnalogOutput2_MaxMissedTicks
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 22;

                    ;% WaterTankSysControl2024_P.RepeatingSequenceStair1_OutValues
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 23;

                    ;% WaterTankSysControl2024_P.AnalogInput1_YieldWhenWaiting
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 27;

                    ;% WaterTankSysControl2024_P.AnalogInput2_YieldWhenWaiting
                    section.data(19).logicalSrcIdx = 18;
                    section.data(19).dtTransOffset = 28;

                    ;% WaterTankSysControl2024_P.AnalogOutput1_YieldWhenWaiting
                    section.data(20).logicalSrcIdx = 19;
                    section.data(20).dtTransOffset = 29;

                    ;% WaterTankSysControl2024_P.AnalogOutput2_YieldWhenWaiting
                    section.data(21).logicalSrcIdx = 20;
                    section.data(21).dtTransOffset = 30;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section

            section.nData     = 12;
            section.data(12)  = dumData; %prealloc

                    ;% WaterTankSysControl2024_P.AnalogInput1_Channels
                    section.data(1).logicalSrcIdx = 21;
                    section.data(1).dtTransOffset = 0;

                    ;% WaterTankSysControl2024_P.AnalogInput2_Channels
                    section.data(2).logicalSrcIdx = 22;
                    section.data(2).dtTransOffset = 1;

                    ;% WaterTankSysControl2024_P.AnalogOutput1_Channels
                    section.data(3).logicalSrcIdx = 23;
                    section.data(3).dtTransOffset = 2;

                    ;% WaterTankSysControl2024_P.AnalogOutput2_Channels
                    section.data(4).logicalSrcIdx = 24;
                    section.data(4).dtTransOffset = 3;

                    ;% WaterTankSysControl2024_P.AnalogInput1_RangeMode
                    section.data(5).logicalSrcIdx = 25;
                    section.data(5).dtTransOffset = 4;

                    ;% WaterTankSysControl2024_P.AnalogInput2_RangeMode
                    section.data(6).logicalSrcIdx = 26;
                    section.data(6).dtTransOffset = 5;

                    ;% WaterTankSysControl2024_P.AnalogOutput1_RangeMode
                    section.data(7).logicalSrcIdx = 27;
                    section.data(7).dtTransOffset = 6;

                    ;% WaterTankSysControl2024_P.AnalogOutput2_RangeMode
                    section.data(8).logicalSrcIdx = 28;
                    section.data(8).dtTransOffset = 7;

                    ;% WaterTankSysControl2024_P.AnalogInput1_VoltRange
                    section.data(9).logicalSrcIdx = 29;
                    section.data(9).dtTransOffset = 8;

                    ;% WaterTankSysControl2024_P.AnalogInput2_VoltRange
                    section.data(10).logicalSrcIdx = 30;
                    section.data(10).dtTransOffset = 9;

                    ;% WaterTankSysControl2024_P.AnalogOutput1_VoltRange
                    section.data(11).logicalSrcIdx = 31;
                    section.data(11).dtTransOffset = 10;

                    ;% WaterTankSysControl2024_P.AnalogOutput2_VoltRange
                    section.data(12).logicalSrcIdx = 32;
                    section.data(12).dtTransOffset = 11;

            nTotData = nTotData + section.nData;
            paramMap.sections(2) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% WaterTankSysControl2024_P.LimitedCounter_uplimit
                    section.data(1).logicalSrcIdx = 33;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(3) = section;
            clear section

            section.nData     = 10;
            section.data(10)  = dumData; %prealloc

                    ;% WaterTankSysControl2024_P.RateTransition1_InitialCondition
                    section.data(1).logicalSrcIdx = 34;
                    section.data(1).dtTransOffset = 0;

                    ;% WaterTankSysControl2024_P.DiscreteFIRFilter1_InitialStates
                    section.data(2).logicalSrcIdx = 35;
                    section.data(2).dtTransOffset = 1;

                    ;% WaterTankSysControl2024_P.DiscreteFIRFilter1_Coefficients
                    section.data(3).logicalSrcIdx = 36;
                    section.data(3).dtTransOffset = 2;

                    ;% WaterTankSysControl2024_P.Delay_InitialCondition
                    section.data(4).logicalSrcIdx = 37;
                    section.data(4).dtTransOffset = 7;

                    ;% WaterTankSysControl2024_P.ActivationGainTANK3_Gain
                    section.data(5).logicalSrcIdx = 38;
                    section.data(5).dtTransOffset = 9;

                    ;% WaterTankSysControl2024_P.SaturationTANK3_UpperSat
                    section.data(6).logicalSrcIdx = 39;
                    section.data(6).dtTransOffset = 10;

                    ;% WaterTankSysControl2024_P.SaturationTANK3_LowerSat
                    section.data(7).logicalSrcIdx = 40;
                    section.data(7).dtTransOffset = 11;

                    ;% WaterTankSysControl2024_P.ActivationGainTANK4_Gain
                    section.data(8).logicalSrcIdx = 41;
                    section.data(8).dtTransOffset = 12;

                    ;% WaterTankSysControl2024_P.SaturationTANK4_UpperSat
                    section.data(9).logicalSrcIdx = 42;
                    section.data(9).dtTransOffset = 13;

                    ;% WaterTankSysControl2024_P.SaturationTANK4_LowerSat
                    section.data(10).logicalSrcIdx = 43;
                    section.data(10).dtTransOffset = 14;

            nTotData = nTotData + section.nData;
            paramMap.sections(4) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% WaterTankSysControl2024_P.Constant_Value
                    section.data(1).logicalSrcIdx = 44;
                    section.data(1).dtTransOffset = 0;

                    ;% WaterTankSysControl2024_P.Output_InitialCondition
                    section.data(2).logicalSrcIdx = 45;
                    section.data(2).dtTransOffset = 1;

                    ;% WaterTankSysControl2024_P.FixPtConstant_Value
                    section.data(3).logicalSrcIdx = 46;
                    section.data(3).dtTransOffset = 2;

            nTotData = nTotData + section.nData;
            paramMap.sections(5) = section;
            clear section


            ;%
            ;% Non-auto Data (parameter)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        paramMap.nTotData = nTotData;



    ;%**************************
    ;% Create Block Output Map *
    ;%**************************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 2;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc sigMap
        ;%
        sigMap.nSections           = nTotSects;
        sigMap.sectIdxOffset       = sectIdxOffset;
            sigMap.sections(nTotSects) = dumSection; %prealloc
        sigMap.nTotData            = -1;

        ;%
        ;% Auto data (WaterTankSysControl2024_B)
        ;%
            section.nData     = 6;
            section.data(6)  = dumData; %prealloc

                    ;% WaterTankSysControl2024_B.OffsetFreeReferenceSignaly_refk
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% WaterTankSysControl2024_B.ReferenceSignal
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% WaterTankSysControl2024_B.OriginalOutput
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% WaterTankSysControl2024_B.NoiseReducedOutput
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

                    ;% WaterTankSysControl2024_B.ActualInput
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 4;

                    ;% WaterTankSysControl2024_B.Sum1
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 5;

            nTotData = nTotData + section.nData;
            sigMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% WaterTankSysControl2024_B.FixPtSwitch
                    section.data(1).logicalSrcIdx = 6;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(2) = section;
            clear section


            ;%
            ;% Non-auto Data (signal)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        sigMap.nTotData = nTotData;



    ;%*******************
    ;% Create DWork Map *
    ;%*******************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 4;
        sectIdxOffset = 2;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc dworkMap
        ;%
        dworkMap.nSections           = nTotSects;
        dworkMap.sectIdxOffset       = sectIdxOffset;
            dworkMap.sections(nTotSects) = dumSection; %prealloc
        dworkMap.nTotData            = -1;

        ;%
        ;% Auto data (WaterTankSysControl2024_DW)
        ;%
            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% WaterTankSysControl2024_DW.DiscreteFIRFilter1_states
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% WaterTankSysControl2024_DW.Delay_DSTATE
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 4;

                    ;% WaterTankSysControl2024_DW.RateTransition1_Buffer0
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 6;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 5;
            section.data(5)  = dumData; %prealloc

                    ;% WaterTankSysControl2024_DW.AnalogInput1_PWORK
                    section.data(1).logicalSrcIdx = 3;
                    section.data(1).dtTransOffset = 0;

                    ;% WaterTankSysControl2024_DW.AnalogInput2_PWORK
                    section.data(2).logicalSrcIdx = 4;
                    section.data(2).dtTransOffset = 1;

                    ;% WaterTankSysControl2024_DW.ScopeTANK2_PWORK.LoggedData
                    section.data(3).logicalSrcIdx = 5;
                    section.data(3).dtTransOffset = 2;

                    ;% WaterTankSysControl2024_DW.AnalogOutput1_PWORK
                    section.data(4).logicalSrcIdx = 6;
                    section.data(4).dtTransOffset = 4;

                    ;% WaterTankSysControl2024_DW.AnalogOutput2_PWORK
                    section.data(5).logicalSrcIdx = 7;
                    section.data(5).dtTransOffset = 5;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% WaterTankSysControl2024_DW.DiscreteFIRFilter1_circBuf
                    section.data(1).logicalSrcIdx = 8;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(3) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% WaterTankSysControl2024_DW.Output_DSTATE
                    section.data(1).logicalSrcIdx = 9;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(4) = section;
            clear section


            ;%
            ;% Non-auto Data (dwork)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        dworkMap.nTotData = nTotData;



    ;%
    ;% Add individual maps to base struct.
    ;%

    targMap.paramMap  = paramMap;
    targMap.signalMap = sigMap;
    targMap.dworkMap  = dworkMap;

    ;%
    ;% Add checksums to base struct.
    ;%


    targMap.checksum0 = 1658457588;
    targMap.checksum1 = 1553399214;
    targMap.checksum2 = 2898911741;
    targMap.checksum3 = 2528487444;

