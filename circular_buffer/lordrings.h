/******************************************************************************************
Copyright           : 2000-2004,FXL.
FileName            :
Author              : Sail(ZENGXING)//Author name here
Version             :
Date Of Creation    : 2006年3月11日
Description         : 一个循环的DEQUE,可以控制在数据满的情况下，是否覆盖
 
Others              : 原来取名cyc_deque，但是一天和Linker聊天他说说他写的类似的类名字是rings，我觉得这个
                        名字比较酷，所以选择这个名字，越来越觉得这个类好用。
Function List       :
1.  ......
Modification History:
1.Date  :
Author  :
Modification  :
喔姐姐，我想回家，牵着我的手，我有些困了
 
******************************************************************************************/
 
 
#ifndef _ZEN_EXTEND_STD_CYC_DEQUE_H_
#define _ZEN_EXTEND_STD_CYC_DEQUE_H_
 
#include <string.h>
#include <assert.h>
 
namespace zenlib
{
 
template<class _value_type >
class lordrings
{
protected:
    //循环队列的起始位置
    size_t                cycdeque_start_;
    //循环队列的结束位置，注意我使用的是前开后闭
    size_t                cycdeque_end_;
    //队列的长度，使队列的容量+1
    size_t                cycdeque_len_;
    //存放数据的指针
    _value_type           *value_ptr_;
 
public:
    //构造函数，后面必须调用,initialize
    lordrings():
        cycdeque_start_(0),
        cycdeque_end_(cycdeque_start_),
        cycdeque_len_(1),
        value_ptr_(NULL)
    {
    }
   
    //构造函数，后面完全没有必要调用,initialize
    //因为要形成一个前闭后开的空间，所以cycdeque_len_比实际要求的数据长度+1
    lordrings(size_t data_len):
        cycdeque_start_(0),
        cycdeque_end_(cycdeque_start_),
        cycdeque_len_(data_len+1),
        value_ptr_(NULL)
    {
        assert(data_len > 0);
        value_ptr_ = new _value_type[cycdeque_len_];
    }
 
    ~lordrings()
    {
        if(value_ptr_)
        {
            delete[] value_ptr_;
            value_ptr_ = NULL;
        }
    }
   
    //因为要形成一个前闭后开的空间，所以cycdeque_len_比实际要求的数据长度+1
    void initialize(size_t data_len)
    {
        assert(data_len > 0);
 
        cycdeque_start_ =0;
        cycdeque_end_ = cycdeque_start_;
        cycdeque_len_ = data_len+1;
        //清理现场
        if(value_ptr_)
        {
            delete[] value_ptr_;
            value_ptr_ = NULL;
        }
        value_ptr_ = new _value_type[cycdeque_len_];
    }
 
    //
    void finit()
    {
        cycdeque_start_ = 0;
        cycdeque_end_ = cycdeque_start_;
        cycdeque_len_ = 1;
        //清理现场
        if(value_ptr_)
        {
            delete[] value_ptr_;
            value_ptr_ = NULL;
        }
    }
 
    //重新
    void clear()
    {
        cycdeque_start_ =0;
        cycdeque_end_ = cycdeque_start_;
    }
       
    //尺寸空间
    inline size_t size() const
    {
        //
        if ( cycdeque_end_ >= cycdeque_start_ )
        {
            return cycdeque_end_ - cycdeque_start_ ;
        }
        else
        {
            return cycdeque_end_+cycdeque_len_ -cycdeque_start_ ;
        }
    }
    //返回空闲空间的大小
    inline size_t freesize() const
    {
        return cycdeque_len_ -size() -1;
    }
    //返回队列的容量
    inline size_t capacity() const
    {
        return cycdeque_len_ -1;
    }
    //检查是否已经满了
    inline bool full() const
    {
        //如果结束+1%
        if((cycdeque_end_ + 1)%cycdeque_len_ ==cycdeque_start_)
        {
            return true;
        }
        return false;
    }
 
    //判断队列是否为空
    inline bool empty() const
    {
        //如果发现开始==结束
        if(cycdeque_start_ == cycdeque_end_)
        {
            return true;
        }
        return false;
    }
 
    //重新分配一个空间,
    bool resize(size_t new_size)
    {
        assert(new_size > 0);
 
        size_t deque_size = size();
        //如果原来的尺寸大于新的尺寸，无法扩展
        if( deque_size > new_size )
        {
            return false;
        }
        _value_type *new_value_ptr = new _value_type[new_size+1];
 
        //调整几个内部参数
        cycdeque_start_ =0;
        cycdeque_end_ = deque_size;
        cycdeque_len_ = new_size+1;
       
        //如果原来有数据
        if(value_ptr_ != NULL)
        {
            for (size_t i=0;i<deque_size;++i)
            {
                new_value_ptr[i] = value_ptr_[(cycdeque_start_+i)%cycdeque_len_];
            }
            delete[] value_ptr_;
            value_ptr_ = NULL;
        }
 
        value_ptr_ = new_value_ptr;
        return true;
    }
 
    //将一个数据放入队列的尾部,如果队列已经满了,你可以将lay_over参数置位true,覆盖原有的数据
    bool push_back(const _value_type &value_data,bool lay_over =false)
    {  
        //
        if((cycdeque_end_ + 1)%cycdeque_len_ ==cycdeque_start_ )
        {
            //如果不要覆盖，返回错误
            if(lay_over == false)
            {
                return false;
            }
            //如果要覆盖
            else
            {
                //将最后一个位置覆盖，并且调整起始和结束位置
                value_ptr_[cycdeque_end_] = value_data;
                cycdeque_start_ = (cycdeque_start_ +1 ) % cycdeque_len_;
                cycdeque_end_ = (cycdeque_end_+1) % cycdeque_len_;
                return true;
            }
        }
        //
        value_ptr_[cycdeque_end_] = value_data;
        cycdeque_end_ = (cycdeque_end_+1) % cycdeque_len_;
        return true;
    }
 
    //从队列的前面得到一个数据
    bool pop_front(_value_type &value_data)
    {
        //
        if (size() == 0)
        {
            return false;
        }
        value_data = value_ptr_[cycdeque_start_];
        cycdeque_start_ = (cycdeque_start_ +1 ) % cycdeque_len_;
        return true;
    }
 
    bool pop_front()
    {
        //
        if (size() == 0)
        {
            return false;
        }
        cycdeque_start_ = (cycdeque_start_ +1 ) % cycdeque_len_;
        return true;
    }
 
    //从队列的前面得到一个数据
    bool pop_end(_value_type &value_data)
    {
        //
        if (size() == 0)
        {
            return false;
        }
 
        cycdeque_end_ = (cycdeque_end_ > 0)?cycdeque_end_-1:cycdeque_len_-1;
        value_data = value_ptr_[cycdeque_end_];
       
        return true;
    }
 
 
    bool pop_end()
    {
        //
        if (size() == 0)
        {
            return false;
        }
        cycdeque_end_ = (cycdeque_end_ > 0)?cycdeque_end_-1:cycdeque_len_-1;
        return true;
    }
   
    //ID不要越界，自己保证，我没兴趣为你干什么
    _value_type& operator[](size_t id)
    {
        return value_ptr_[(cycdeque_start_ + id) % cycdeque_len_];
    }
 
};
 
};
 
#endif //#ifndef _ZEN_EXTEND_STD_CYC_DEQUE_H_
