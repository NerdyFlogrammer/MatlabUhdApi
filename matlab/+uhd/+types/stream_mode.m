classdef stream_mode 
    properties(Constant)
        STREAM_MODE_START_CONTINUOUS =   (int32('a')),
        STREAM_MODE_STOP_CONTINUOUS  =  (int32('o')),
        STREAM_MODE_NUM_SAMPS_AND_DONE = (int32('d')),
        STREAM_MODE_NUM_SAMPS_AND_MORE = (int32('m'))
   end
end

