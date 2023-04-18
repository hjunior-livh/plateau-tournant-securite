

#include <errno.h>
#include <unistd.h>
#include <memory>

#include "tools.hpp"

#if __cplusplus <= 201103L
// helper if the current compiler only supports C++11
#include "make_unique.hpp"
#endif



using namespace GPIO::Tools;

void AutoFile::open(const std::string& name, int mode)
{
    close();
    if ((m_fd = ::open(name.c_str(), mode)) < 0) throw ToolsError(std::string("cannot open file: ") + std::strerror(errno));
}

bool AutoFile::open_nothrow(const std::string& name, int mode) noexcept
{
    if (m_fd >= 0) {
        if (::close(m_fd) < 0) return false;
        m_fd = -1;
    }
    if ((m_fd = ::open(name.c_str(), mode)) < 0) return false;
    return true;
}

ssize_t AutoFile::read(void *buf, size_t count) const
{
    ssize_t rb = ::read(m_fd, buf, count);
    if (rb < 0) throw ToolsError(std::string("cannot read file: ") + std::strerror(errno));
    if (static_cast<size_t>(rb) != count) throw ToolsError("cannot read file, not all data read");
    return rb;
}

void AutoFile::write(const void *buf, size_t count) const
{
    ssize_t wb = ::write(m_fd, buf, count);
    if (wb < 0) throw ToolsError(std::string("cannot write file: ") + std::strerror(errno));
    if (static_cast<size_t>(wb) != count) throw ToolsError("cannot write file, not all data written");
}

off_t AutoFile::seek(off_t offset, int whence)
{
    off_t offs = ::lseek(m_fd, offset, whence);
    if (offs < 0) throw ToolsError(std::string("cannot seek file: ") + std::strerror(errno));
    return offs;
}

void AutoFile::close()
{
    if (m_fd < 0) return;
    if (::close(m_fd) < 0) throw ToolsError(std::string("cannot close file: ") + std::strerror(errno));
    m_fd = -1;
}

AutoFile::~AutoFile()
{
    if (m_fd >= 0) ::close(m_fd);
}

