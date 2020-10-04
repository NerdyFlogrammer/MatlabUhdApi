% tune_request Creates a tune request struct
%
% Inputs:
%
%   targetFreq:    The RF frequency in Hz. Set when the policy is set to
%                   manual. (optional, default 0)
%
%   lo_off    :    LO offset frequency in Hz. (optional)
function [tr] = tune_request(targetFreq, loOff)
    narginchk(0,2);
    switch nargin           
        case 1
            tr.target_freq = targetFreq;
        case 2
            tr.target_freq = targetFreq;
            tr.rf_freq = targetFreq + loOff;
            tr.rf_freq_policy = policy.POLICY_MANUAL;
        otherwise
            tr.target_freq = 0;
    end
end
