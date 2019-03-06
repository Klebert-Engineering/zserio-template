# What is this project about?
This project demonstrates how a zserio PoC version with template support can be used to 
model a basic concept like a attribute map and apply it for different specific modules.

It contains: 
* A zserio version (zserio.jar + runtime) that can be used to generate C++ sources with templates
* zserio schema that uses templates
* A demo that demonstrates serialization/deserialization of templated zserio structs

# Limitations of the template support
* sources must be generated with withoutSourcesAmalgamation, because templated header just include the generated cpp file
* nested templates are not yet supported
* templates can be only instatiated with structs and choices - no arrays, no simple types like int, string ...


