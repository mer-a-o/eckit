ecbuild_add_executable( TARGET      eckit_version
                        OUTPUT_NAME eckit-version
                        SOURCES     eckit-version.cc
                        LIBS        eckit )

### NOT TO INSTALL

ecbuild_add_executable( TARGET      dhcopy
                        OUTPUT_NAME eckit-dhcopy
                        NOINSTALL
                        SOURCES     dhcopy.cc
                        LIBS        eckit_option eckit )

ecbuild_add_executable( TARGET      syslog_server
                        OUTPUT_NAME eckit-syslog-server
                        NOINSTALL
                        SOURCES     syslog-server.cc
                        LIBS        eckit )

ecbuild_add_executable( TARGET      syslog_client
                        OUTPUT_NAME eckit-syslog-client
                        NOINSTALL
                        SOURCES     syslog-client.cc
                        LIBS        eckit )

