from conans import ConanFile

class QtChartsConan(ConanFile):
    name = "QtCharts"
    version = "5.7.0"
    settings = "os", "compiler", "build_type", "arch"
    url = "https://github.com/qtproject/qtcharts.git"
    license = "GPL3"
    generators = "qmake", "cmake", "gcc"
    folder_name = "qtcharts"

    def source(self):
        self.run( "git clone %s %s" %  (self.url, self.folder_name))

    def build(self):
        self.run( "cd %s && qmake CONFIG+=debug_and_release" % self.folder_name )
        if self.settings.build_type == "Debug":
            self.run( "cd %s && make debug" % self.folder_name )
        else:
            self.run( "cd %s && make release" % self.folder_name )

    def package(self):
        self.copy( pattern="libQt5Charts.*", dst="lib", src="%s/lib" % self.folder_name)
        self.copy( pattern="*", dst="include", src="%s/include" % self.folder_name)
        self.copy( pattern="*[!_p].h", dst="src", src="%s/src" % self.folder_name)
        self.copy( pattern="*.cmake", dst="lib/cmake", src="%s/lib/cmake" % self.folder_name)

    def package_info(self):
        self.cpp_info.libs.extend(["Qt5Charts"])
        self.cpp_info.includedirs.extend([ 'include', 'include/QtCharts'])
