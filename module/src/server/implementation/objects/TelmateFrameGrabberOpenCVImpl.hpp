/* Autogenerated with kurento-module-creator */

#ifndef __TELMATE_FRAME_GRABBER_OPENCV_IMPL_HPP__
#define __TELMATE_FRAME_GRABBER_OPENCV_IMPL_HPP__

#include <OpenCVProcess.hpp>
#include "TelmateFrameGrabber.hpp"
#include <EventHandler.hpp>
#include <gst/gst.h>
#include "VideoFrame.hpp"

#include <boost/asio/io_service.hpp>
#include <boost/bind.hpp>
#include <boost/thread/thread.hpp>

#include <boost/thread/thread.hpp>
#include <boost/lockfree/queue.hpp>
#include <iostream>

#include <boost/atomic.hpp>

namespace kurento
{

class TelmateFrameGrabberOpenCVImpl : public virtual OpenCVProcess
{

public:

  TelmateFrameGrabberOpenCVImpl ();

  virtual ~TelmateFrameGrabberOpenCVImpl () {};

  virtual void process (cv::Mat &mat);

protected:
    std::shared_ptr<MediaObject> getSharedPtr()
    {
        try {
            return dynamic_cast <MediaObject *> (this)->shared_from_this();
        } catch (...) {
            return std::shared_ptr<MediaObject> ();
        }
    }


private:
    boost::asio::io_service ioService;
    boost::thread_group tp;
    boost::lockfree::queue<VideoFrame*> *frameQueue;
    boost::thread* thr;
    void queueHandler();

};

} /* kurento */

#endif /*  __TELMATE_FRAME_GRABBER_OPENCV_IMPL_HPP__ */
