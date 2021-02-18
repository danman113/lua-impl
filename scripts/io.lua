print("Data from command line args:")
argstring = ""
for _, arg in ipairs(arg) do
    argstring = arg .. " "
end
print(argstring)

print("Data from stdin:")
instring = io.read("*line") -- First parameter determines how input is 
print(instring)

print("Data from file:")
filehandle = io.open("io.lua", "r") -- filname, permission
filestring = filehandle:read("*all") -- same args as io.read()
print(filestring)

print("Did you get all that (Y/n)")
rerun = io.read("*line")
if rerun ~= "n" then
    print("Rerunning everything")
    load(filestring)()
else
    print("Goodbye!")
end