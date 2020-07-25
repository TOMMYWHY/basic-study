import torch
import torchvision
import torch.nn as nn
import torch.optim as optim
import torchvision.transforms as transforms
from model import LetNet
import matplotlib.pyplot as plt
import numpy as np



transform = transforms.Compose(
    [transforms.ToTensor(),
     transforms.Normalize((0.5, 0.5, 0.5), (0.5, 0.5, 0.5))])

train_set = torchvision.datasets.CIFAR10(root='./data', train=True,
                                        download=True, transform=transform)

train_loader = torch.utils.data.DataLoader(train_set, batch_size=36,
                                          shuffle=True, num_workers=0)


val_set = torchvision.datasets.CIFAR10(root='./data', train=False,
                                       download=False, transform=transform)
val_loader = torch.utils.data.DataLoader(val_set, batch_size=10000,
                                         shuffle=False, num_workers=0)

val_data_iter = iter(val_loader)
val_image, val_label = val_data_iter.next()

classes = ('plane', 'car', 'bird', 'cat',
           'deer', 'dog', 'frog', 'horse', 'ship', 'truck')

# def imshow(img):
#     img=img/2 +.5
#     npimg=img.numpy()
#     plt.imshow(np.transpose(npimg,(1,2,0)))
#     plt.show()
#
# print("".join("%5s" % classes[val_label[j]] for j in range(4)))
# imshow(torchvision.utils.make_grid(val_image))


net = LetNet()
loss_function=nn.CrossEntropyLoss()
optimizer = optim.Adam(net.parameters(), lr=0.001)

for epoch in range(5):
    running_loss = 0.0
    for step, data in enumerate(train_loader, start=0):
        # print(step) # 每一个step 计算一个batch 36张图片
        inputs, labels = data
        optimizer.zero_grad()
        outputs = net(inputs)
        loss = loss_function(outputs, labels)
        loss.backward()
        optimizer.step()

        running_loss += loss.item()
        if step % 500 == 499:  # print every 500 mini-batches
            with torch.no_grad():
                outputs = net(val_image)  # [batch, 10]
                predict_y = torch.max(outputs, dim=1)[1]
                accuracy = (predict_y == val_label).sum().item() / val_label.size(0) #没500batch 计算一次测试集结果

                print('[%d, %5d] train_loss: %.3f  test_accuracy: %.3f' %
                      (epoch + 1, step + 1, running_loss / 500, accuracy))
                running_loss = 0.0

print('Finished Training')

save_path = './Lenet.pth'
torch.save(net.state_dict(), save_path)
