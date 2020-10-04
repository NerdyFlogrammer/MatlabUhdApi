function [streamArgs] = stream_args(cpu,otw)
switch nargin
    case 0
        cpu = "";
        otw = "";
    case 1
        otw = "";
end
streamArgs.cpu_format = cpu;
streamArgs.otw_format = otw;
streamArgs.args = struct;
streamArgs.channels = [];
end

